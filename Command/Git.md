## SETUP

Configuring user information used across all local repositories
``` py
git config --global user.name “[firstname lastname]”
```
set a name that is identifiable for credit when review version history

```py
git config --global user.email “[valid-email]”
```
set an email address that will be associated with each history marker
```py
git config --global color.ui auto
```
set automatic command line coloring for Git for easy reviewing

## SETUP & INIT
Configuring user information, initializing and cloning repositories
```py
git init
```
initialize an existing directory as a Git repository
```py
git clone [url]
```
retrieve an entire repository from a hosted location via URL

## STAGE & SNAPSHOT

Working with snapshots and the Git staging area
```py
git status
```
show modified files in working directory, staged for your next commit
```py
git add [file]
```
add a file as it looks now to your next commit (stage)
```py
git reset [file]
```
unstage a file while retaining the changes in working directory
```py
git diff
```
diff of what is changed but not staged

```py
git diff --staged
```
diff of what is staged but not yet committed

```py
git commit -m “[descriptive message]”
```
commit your staged content as a new commit snapshot

## BRANCH & MERGE

Isolating work in branches, changing context, and integrating changes
```py
git branch
```
list your branches. a * will appear next to the currently active branch
```py
git branch [branch-name]
```
create a new branch at the current commit
```py
git checkout
```
switch to another branch and check it out into your working directory
```py
git merge [branch]
```
merge the specified branch’s history into the current one
```py
git log
```
show all commits in the current branch’s history

## INSPECT & COMPARE

Examining logs, diffs and object information
```py
git log
```
show the commit history for the currently active branch
```py
git log branchB..branchA
```
show the commits on branchA that are not on branchB
```py
git log --follow [file]
```
show the commits that changed file, even across renames
```py
git diff branchB...branchA
```
show the diff of what is in branchA that is not in branchB
```py
git show [SHA]
```
show any object in Git in human-readable format

## TRACKING PATH CHANGES

Versioning file removes and path changes
```py
git rm [file]
```
delete the file from project and stage the removal for commit
```py
git mv [existing-path] [new-path]
```
change an existing file path and stage the move
```py
git log --stat -M
```
show all commit logs with indication of any paths that moved

## IGNORING PATTERNS

Save a file with desired patterns as .gitignore with either direct string matches or wildcard globs.
```PY
logs/*.notes pattern*/
```
```py
git config --global core.excludesfile [file]
```
system wide ignore pattern for all local repositories

## SHARE & UPDATE
Retrieving updates from another repository and updating local repos
```py
git remote add [alias] [url]
```
add a git URL as an alias
```py
git fetch [alias]
```
fetch down all the branches from that Git remote
```py
git merge [alias]/[branch]
```
merge a remote branch into your current branch to bring it up to date
```py
git push [alias] [branch]
```
Transmit local branch commits to the remote repository branch
```py
git pull
```
fetch and merge any commits from the tracking remote branch

## REWRITE HISTORY
Rewriting branches, updating commits and clearing history
```py
git rebase [branch]
```
apply any commits of current branch ahead of specified one
```py
git reset --hard [commit]
```
clear staging area, rewrite working tree from specified commit

## TEMPORARY COMMITS
Temporarily store modified, tracked files in order to change branches
```py
git stash
```
Save modified and staged changes
```py
git stash list
```
list stack-order of stashed file changes
```py
git stash pop
```
write working from top of stash stack
```py
git stash drop
```
discard the changes from top of stash stack