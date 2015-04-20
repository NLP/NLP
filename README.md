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
```
1. Tokenize Input into Tokens
2. Tag Tokens with POS Tags
3. Determine the most probable Tag for each Token
4. Parse Tokens into Syntax Tree using Grammar Structure
5. Determine Head Verb/Noun of the Tree and each of its Sub-Trees
6. Determine the most probable Tree
7. Create Relationship Diagram from the Tree
```
Link on submodules : https://chrisjean.com/git-submodules-adding-using-removing-and-updating/


