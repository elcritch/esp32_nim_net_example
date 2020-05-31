#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <errno.h>
#include <pthread.h>

#include <ei.h>
#include <ei_connect.h>
#include <erl_interface.h>
// #include <erl_format.h>

#define BUFSIZE 1000

int new_ei_x_size(ei_x_buff *x, long size);
void set_node_reply(ei_x_buff *x_out, long val);
void *ei_malloc(long size);

int main(int argc, char **argv)
{

  int port = atoi(argv[1]);

  ei_init();

  struct in_addr addr; /* 32-bit IP number of host */
  addr.s_addr = inet_addr("127.0.0.1");

  ei_cnode ec;
  if (ei_connect_xinit(
        &ec,
        "alpha",
        "cnode",
        "cnode@127.0.0.1",
        &addr,
        "secretcookie",
        0) < 0) {
    fprintf(stderr, "ERROR: when initializing: %d\n", h_errno);
    exit(-1);
  }

  /* Make a listen socket */
  int listen;          /* Listen socket */
  if ((listen = my_listen(port)) <= 0) {
    fprintf(stderr, "ERROR: listening: %d on port %d\n", listen, port);
    exit(-1);
  }

  if (ei_publish(&ec, port) == -1)
  {
    fprintf(stderr, "ERROR: publishing on port %d\n", port);
    exit(-1);
  }

  int fd;
  ErlConnect conn;               /* Connection data */
  if ((fd = ei_accept(&ec, listen, &conn)) == ERL_ERROR) {
    fprintf(stderr, "ERROR: erl_accept on listen socket %d\n", listen);
    exit(-1);
  }

  fprintf(stdout, "listening on port: %d\n\r", port);
  fprintf(stdout, "Connected to %s\n\r", conn.nodename);

  erlang_msg info;
  ei_x_buff emsg;
  ei_x_buff x_out;
  new_ei_x_size(&emsg, 128);

  int loop = 1;               /* Lopp flag */
  while (loop)
  {

    int got = ei_receive_msg(fd, &info, &emsg);

    if (got == ERL_TICK)
    {
      fprintf(stdout, "tick: %d\n", got);
      /* ignore */
    }
    else if (got == ERL_ERROR)
    {
      fprintf(stdout, "erl_error: %d\n", got);
      loop = 0;
    }
    else
    {

      // ETERM *fromp, *tuplep, *fnp, *argp, *resp;
      fprintf(stdout, "message: %d\n", got);
      if (info.msgtype == ERL_REG_SEND)
      {
        int res = 0;
        int version;
        int arity;
        char msg_atom[MAXATOMLEN + 1] = {0};
        char *msg_print = malloc(1024);
        long msg_arg;
        erlang_pid pid;

        fprintf(stdout, "erl_reg_send: msgtype: %ld buff: %p idx: %d bufsz: %d \n",
                          info.msgtype, emsg.buff, emsg.index, emsg.buffsz);

        emsg.index = 0;
        ei_s_print_term(&msg_print , emsg.buff, &emsg.index);
        fprintf(stdout, "term: `%s`\n", msg_print);

        emsg.index = 0;
        if (ei_decode_version(emsg.buff, &emsg.index, &version) < 0) {
          fprintf(stderr, "ignoring malformed message (bad version: %d)\n", version);
          return -1;
        }
        if (ei_decode_tuple_header(emsg.buff, &emsg.index, &arity) < 0) {
          fprintf(stderr, "ignoring malformed message (not tuple)\n");
          return -1;
        }
        if (arity != 3) {
          fprintf(stderr, "ignoring malformed message (must be a 3-arity tuple)\n");
          return -1;
        }
        if (ei_decode_atom(emsg.buff, &emsg.index, msg_atom) < 0) {
          fprintf(stderr, "ignoring malformed message (first tuple element not atom)\n");
          return -1;
        }
        if (ei_decode_pid(emsg.buff, &emsg.index, &pid) < 0) {
          fprintf(stderr, "ignoring malformed message (first tuple element of second tuple element not pid)\n");
          return -1;
        }
        if (ei_decode_tuple_header(emsg.buff, &emsg.index, &arity) < 0 || arity != 2) {
          fprintf(stderr, "ignoring malformed message (second tuple element not 2-arity tuple)\n");
          return -1;
        }
        if (ei_decode_atom(emsg.buff, &emsg.index, msg_atom) < 0) {
          fprintf(stderr, "ignoring malformed message (first message tuple element not atom)\n");
          return -1;
        }
        if (ei_decode_long(emsg.buff, &emsg.index, &msg_arg) < 0) {
          fprintf(stderr, "ignoring malformed message (second message tuple element not an int)\n");
          return -1;
        }

        if (strncmp(msg_atom, "foo", 3) == 0) {
          fprintf(stderr, "foo: %ld\n", msg_arg);
          res = foo(msg_arg);
        }
        else if (strncmp(msg_atom, "bar", 3) == 0) {
          fprintf(stderr, "bar: %ld\n", msg_arg);
          res = bar(msg_arg);
        }
        else {
          fprintf(stderr, "other: %ld\n", msg_arg);
          fprintf(stderr, "other message: %s\n", msg_atom);
        }

        // set_node_reply(&x_out, msg_arg);

        x_out.index = 0;
        ei_x_format(&x_out, "{cnode,~i}", msg_arg);
        ei_send(fd, &info.from, x_out.buff, x_out.index);

        // erl_free_term(argp);
      }
    }
  } 
}

int my_listen(int port) {
  int listen_fd;
  struct sockaddr_in addr;
  int on = 1;

  if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (-1);

  setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

  memset((void *)&addr, 0, (size_t)sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    return (-1);

  listen(listen_fd, 5);
  return listen_fd;
}

void set_node_reply(ei_x_buff *x_out, long val) {
  x_out->index = 0;
  (void)ei_x_encode_version(x_out);
  (void)ei_x_encode_tuple_header(x_out, 2);
  (void)ei_x_encode_atom(x_out, "cnode");
  (void)ei_x_encode_long(x_out, val);
}

int new_ei_x_size(ei_x_buff *x, long size) {
  x->buff = (char *) ei_malloc(size);
  x->buffsz = size;
  x->index = 0;
  return x->buff != NULL ? 0 : -1;
}