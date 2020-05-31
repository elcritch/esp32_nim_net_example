Path.wildcard(:code.root_dir() ++ "/lib/erl_interface-*/") |> Enum.at(0) |> IO.puts()
