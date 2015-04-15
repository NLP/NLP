# Main repository (Read Only)

Join our online chat at [![Gitter](https://badges.gitter.im/gitterHQ/gitter.svg)](https://gitter.im/atomic/nlp)


### Guide
```
1.Clone the repository
2. run `git pull && git submodule update --init --recursive` to automatically update all submodules
3. Work on specific repository separately

On Branching:
Some repository has multiple branches, to pull and work on them : 
    git checkout -b LocalName origin/remotebranchname
```

### Qt Settings
```
Default build directory : ../build-%{CurrentProject:Name}-%{CurrentKit:FileSystemName}-%{CurrentBuild:Name}
```

Link on submodules : https://chrisjean.com/git-submodules-adding-using-removing-and-updating/
