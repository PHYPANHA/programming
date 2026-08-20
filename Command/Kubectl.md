## Command line tool (Kubectl)

Kubernetes provides a command line tool for communicating with a Kubernetes cluster's control plane, using the Kubernetes API.

This tool is named `kubectl`.

For configuration, `kubectl` looks for a file named `config` in the `$HOME/.kube` directory. You can specify other kubeconfig files by setting the `KUBECONFIG` environment variable or by setting the `--kubeconfig` flag.

This overview covers `kubectl` syntax, describes the command operations, and provides common examples. For details about each command, including all the supported flags and subcommands, see the kubectl reference documentation.

For an overview, see The kubectl command-line tool. For installation instructions, see Installing kubectl; for a quick guide, see the cheat sheet. If you're used to using the `docker` command-line tool, `kubectl` for Docker Users explains some equivalent commands for Kubernetes.

### Syntax

Use the following syntax to run `kubectl` commands from your terminal window:

```yanl
kubectl [command] [TYPE] [NAME] [flags]
```

where `command`, `TYPE`, `NAME`, and `flags` are:

- `command`: Specifies the operation that you want to perform on one or more resources, for example `create`, `get`, `describe`, `delete`.

- `TYPE`: Specifies the resource type. Resournce type are case-insensitive and you can specify the singular, plural or abbreviated forms. For example, the following commands produce the same output:

```py
kubectl get pod pod1
kubectl get pods pod1
kubectl get po pod1
```

- `NAME`: Specifies the names of the resource. Names are case-sensitive. If the name is omitted, details for all resources are displayed, for example `kubectl get pods`.

    When performing an operation on multiple resources, you can specify each resource by type and name or specify one or more files:
    
    - To specify resources by type and name:

        - To group resources if they are all the same type: `TYPE1 name1 name2 name<#>`.
        Example: `kubectl get pod example-pod1 example-pod2`

        - To specify multiple resource types individually: `TYPE1/name1 TYPE1/name2 TYPE2/name3 TYPE<#>/name<#>`.
        Example: `kubectl get pod/example-pod1 replicationcontroller/example-rc1`

    - To specify resources with one or more files: `-f file1 -f file2 -f file<#>`
        - Use YAML rather than JSON since YAML tends to be more user-friendly, especially for configuration files.
        Example: `kubectl get -f ./pod.yaml`
- `flags`: Specifies optional flags. For example, you can use the `-s` or `--server` flags to specify the address and port of the Kubernetes API server.