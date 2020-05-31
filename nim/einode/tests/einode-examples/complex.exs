defmodule Complex4 do

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
				IO.puts("other: #{inspect other} ")
		after
			2_000 ->
				IO.puts("timeout: ")
	  end
	end

end
