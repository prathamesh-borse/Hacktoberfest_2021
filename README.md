# Hacktoberfest_2021
📺 Video explanation:- https://youtu.be/apGV9Kg7ics

![68747470733a2f2f692e696d6775722e636f6d2f626b39437675762e706e67](https://user-images.githubusercontent.com/66899360/132447624-a3cba1c3-ea84-4582-8d6c-18404d27aae6.png)

<div align="center">
  <img src="https://visitor-badge.glitch.me/badge?page_id=prathamesh-borse.Hacktoberfest_2021" alt="visitors" />
  <img src="https://img.shields.io/github/issues/prathamesh-borse/Hacktoberfest_2021" alt="GitHub issues" />
  <img src="https://img.shields.io/github/issues-search/prathamesh-borse/Hacktoberfest_2021?label=merged%20PRs&query=is%3Apr+is%3Aclosed+is%3Amerged&color=purple" alt="Merged Pull Requests" />
</div>


## git installation
Install git from this link:- https://git-scm.com/downloads

To check the git version
```
git --vesrion
```
To set the global git username & email address
```![68747470733a2f2f692e696d6775722e636f6d2f626b39437675762e706e67](https://user-images.githubusercontent.com/66899360/132447574-2a07f523-ff4e-46e7-96e0-304bf811752e.png)

git config --global user.name "your name"
git config --global user.email "your email"
```

## STEPS to contribute:
1. Initialize git repository.
```
git init
```
2. Create a new branch.
```
git branch YourBranchName
```
3. Shift to that branch from master branch.
```
git checkout YourBranchName
```
Add your name under ```contributors list``` in README.md with format ```FirstName_LastName```

4. Add all the changes you've made.
```
git add .
```
5. Make a commit message.
```
git commit -m 'your_message'
```
6. Shift to the master branch.
```
git checkout main
```
7. Merge everything from your branch to the master branch.
```
git merge YourBranchName
```
8. Get ready to push from your local machine.
```
git remote add <message> https://<GitHubToken>@github.com/<username>/<RepositoryName>.git
```
If you haven't setup your **Personal Access Token** yet, then follow the steps from [here](https://docs.github.com/en/github/authenticating-to-github/keeping-your-account-and-data-secure/creating-a-personal-access-token).

9. Push everything on your forked repository.
```
git push -u <message> main
```

