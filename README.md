# Main repository (Read Only)
=====================================================

Join our online chat at [![Gitter](https://badges.gitter.im/NLP/gitter.svg)](https://gitter.im/nlp)


### Guide
```
1.Clone the repository
2. run `git pull && git submodule update --init --recursive` to automatically update all submodules
4. run `git submodule foreach --recursive git checkout master`
3. Work on specific repository separately

On Branching:
Some repository has multiple branches, to pull and work on them : 
    ex : git checkout -b Parser origin/Parser
```

### Qt Settings
```
Default build directory : ../build-%{CurrentProject:Name}-%{CurrentKit:FileSystemName}-%{CurrentBuild:Name}
```

# Project Diagram

```sequence
Token->Word->Grammar
```

Link on submodules : https://chrisjean.com/git-submodules-adding-using-removing-and-updating/
