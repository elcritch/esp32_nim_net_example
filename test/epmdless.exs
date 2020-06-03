# A module containing the function that determines the port number
defmodule Epmdless do
  require Logger

  def dist_port(name) when is_atom(name) do
    dist_port Atom.to_string name
  end

  def dist_port(name) when is_list(name) do
    dist_port List.to_string name
  end

  def dist_port(name) when is_binary(name) do
    base_port = :application.get_env :kernel, :inet_dist_base_port, 4370

    node_name = Regex.replace ~r/@.*$/, name, ""
    offset =
      case Regex.run ~r/[0-9]+$/, node_name do
        nil ->
          0
        [offset_as_string] ->
          String.to_integer offset_as_string
      end

    base_port + offset
    |> IO.inspect(label: "dist_port")
  end
end

defmodule Epmdless_epmd_client do
  def start_link do
    :ignore
  end

  def register_node(name, port, _family) do
    register_node(name, port)
  end

  def register_node(_name, _port) do
    creation = :rand.uniform 3
    {:ok, creation}
    |> IO.inspect(label: "register_node")
  end

  def port_please(name, _ip) do
    port = Epmdless.dist_port name
    version = 5

    {:port, port, version}
    |> IO.inspect(label: "port_please")
  end

  def names(_hostname) do
    {:error, :address}
  end
end
