# Git and Github Basic Command to get started

## 1. Git Init

Initializes a new Git Repository in your current directory.
Example: Creae a .git folder

```
$ git init
```

## 2. Git Clone

Clones a remote repository to your local machine.
Exmaple: Copy repository from Github.

```
$ git clone http://github.com/user/project.git
```

## 3. Git Status

Shows the current state of your working directory (modified, staged,etc.).

Example:

``` yaml
On branch main
Modified:
.   file.txt
Untracked:
.   newfile.txt
```

```
$ git status
```

## 4. git add .
Adds changes to the staging area (prepares for commit).

```
$ git add .
```

## 5. Git commit -m "message"

Records the staged changes with a message.

Example:
``` yaml
Commit History

Latest commit abc1234 --> Previous commit 9f8e7d
```

```
$ git commit -m "Update readme file"
. # [main abc1234] Update readme file
```

## 6. Git push

Upload your local commits to a remote repository.

```
git push origin main
```

## 7. git pull

Fetches and merges changes from a remote repository.

```
git pull origin main
```

## 8. git branch

Lists, creates or deletes branches.

Example:
```
main --> feature-login --> old-branch
```

```
$ git branch
$ git branch feature-login
$ git branch -d old-branch
```
### The Git workflow in 6 steps
``` yaml
1. Initialize (Create a new repository.)
2. Modify (Make change to your files.)
3. Check Status (See what's changed.)
4. Add (Stage your changes.)
5. Commit (Save changes with a message.)
6. Push (Share with Github or remote repo.)
```

### Commit practices
- Write clear and meaningful commit messages.
- Use branches for new features or bug fixes.
- Pull regularly to keep your code up to date.
- Keep your repository clean and organized.

### Quick Tips

- Use **.gitignore** for unwanted files.
- Learn Git aliases to save time.
- Use **pull --rebase** for a cleaner history.
- Explore GitHub for collaboration.

### Useful Resources

- Git Documentation http://git-scm.com
- GitHub Guide http://docs.github.com