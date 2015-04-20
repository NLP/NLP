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
# Meaning Representation Scope
```
1. Simple Declarative Sentences with Transitive Verbs (Ex: He kicks the ball)
2. Declarative Sentences with Transitives and Indirect Objects (Ex: He kicks the ball to her)
3. Declaratives with Intransitives (Ex: He kicks)
4. Declaratives with Linking Verbs that state existence or definition (Ex: He is a person)
5. Declaratives with non-specific subjects (Ex: That is a car. Ex: That thing walked)
6. Imperatives with simple Transitives, like a command (Ex: Define an apple. Ex: Draw a square)
7. Imperatives with Indirect Objects and Prepositions (Ex: Show me an apple. Ex: Show me an apple on a table)
8. Simple Y/N Questions for Actions (Ex: Did he kick the ball?)
9. Y/N Questions for Existence and Definition (Ex: Is he a person? Ex: Is that a ball?)
10. Simple Wh-Questions (Ex: What did he kick? Ex: Who is he?)
11. Wh-Questions with Modifiers (Ex: When is the apple on a table?)
```
Link on submodules : https://chrisjean.com/git-submodules-adding-using-removing-and-updating/


