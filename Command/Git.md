## 1. Setup and Initialization

Commands used to start a new repository or configure your Git environment.

- `git init` : **Initializes a branch-new local Git repository** in your current folder.

- `git clone <url>` : **Copies an existing remote repository** to your local machine.

- `git config --global user.name "Your Name"`: **Sets your commit username** globally.

- `git config --global user.email "your@email.com"`: **Sets your commit email** globally.

## 2. The Core Workflow (Stage & Commit)

Commands used to track, review, and save changes locally.

- `git status`: **Shows the current state** of your working directory (tracked vs. untracked files).

- `git add <file>`: **Stages specific file changes** for your next commit.

- `git add .` : **Stages all modified and new files** at once.

- `git commit -m "your message"`: **Saves your staged snapshot** to the local project history.

- `git commit --amend`: **Modifies your last commit** (useful for fixing typos in messages).

## 3. Branching & Merging

Commands used to isolate features and combine separate histories.

- `git branch` : **Lists all local branches** in the repository.
- `git switch -c <branch-name>` : **Creates and switches to a new branch** instantly.
- `git switch <branch-name>` : **Switches back** to an existing branch.
- `git merge <branch-name>` : **Combines another branch's history** into your active branch.
- `git branch -d <branch-name>` : **Deletes a branch** safely once it has been merged.

## 4. Sharing & Syncing (Remotes)

Commands used to synchronize your work with cloud hosts like GitHub or GitLab.
``` py 
git remote add origin <url>
```
 : **Links your local repository** to a remote online hub.
- `git fetch` : **Downloads tracking info** and history from remote without changing your code.
- `git pull` : **Fetches and automatically merges** remote changes into your active local branch.
- `git push origin <branch-name>` : Uploads your local commits to the remote server.5. Inspection & Undoing MistakesCommands used to inspect your history or revert unwanted code alterations.git log --oneline: Displays a concise, clean view of your commit history.git diff: Shows unstaged differences between your current files and last commit.git restore <file>: Discards changes made to a local file, resetting it to the last commit.git reset --hard HEAD: Resets everything (working directory and staging area) to the last saved commit.git stash: Temporarily shelves your uncommitted changes so you can switch branches cleanly.For a complete reference, you can look through the official Git Cheat Sheet.If you would like, let me know:What specific task you are trying to accomplish right now?If you are facing any error messages or merge conflicts?