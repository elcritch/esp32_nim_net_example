defmodule Complex do

   def foo(x, server_id \\ 1) do
     call_cnode({:foo, x}, server_id)
   end

   def bar(y, server_id \\ 1) do
     call_cnode({:bar, y}, server_id)
   end

   def call_cnode(msg, server_id) do
      {:any, :'cnode#{server_id}@127.0.0.1'}
      |> send({:call, self(), msg})

     receive do
       {:cnode, result} ->
         result
       other ->
            IO.puts("error: unexpected: #{inspect other} ")
      after
         2_000 ->
            IO.puts("error: timeout")
            raise "timeout error"
     end
   end

end

Process.sleep(1_000)
IO.puts "Nodes: #{inspect Node.list(:hidden)}"

IO.puts "ok: foo: #{Complex.foo(14)}"
IO.puts "ok: bar: #{Complex.bar(17)}"
System.halt(0)

