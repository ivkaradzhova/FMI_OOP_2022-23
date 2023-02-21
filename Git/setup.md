# Малко информация за започване на работа с github

## Полезни връзки:
https://docs.github.com/en/get-started - основна документация

https://docs.github.com/en/get-started/importing-your-projects-to-github/importing-source-code-to-github/adding-locally-hosted-code-to-github
      
Инсталиране на git: 

windows:
https://linuxhint.com/add-git-bash-windows-terminal/   
linux: (https://phoenixnap.com/kb/how-to-install-git-on-ubuntu)
```
sudo apt update
sudo apt install git
```


## Основни стъпки

1. Регистрация в Github
2. Създайте си репозитори (public/private, няма значение)
3. Трябва да си setup-нем начин за аутентикация   
	3.1 **(Вижте отдолу)\***(По-скоро за компютрите във ФМИ) Create (Fine-grained personal access tokens например) token:    
  https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token   
  Settings -> Developer Options > Generete Token

	3.2 (Ако работите на собствени компютри) Вижте SSH ключа и как може да се използва: примерно https://gist.github.com/bsara/5c4d90db3016814a3d2fe38d314f9c23  ако не стане вижте друг линк
4.  Трябва да си клонирате репото    
    4.1 **(Вижте отдолу)\*** При използване на токен:   
git clone `https://<username>:<token>@github.com/<user>/<repo>.git`; Пример:  git clone `https://Markisimus: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@github.com/Markisimus/test00p.git`

    После може да се наложи да се смени самия ключ, ако се използва personal token:
`git remote set-url origin https://<username>:<token>@github.com/user/<repo>.git`

    4.2 При използване на SSH ключ:   
    `git clone git@github.com:<USer>/<repo>.git` или може би `git clone https://github.com/<user>/<repo>.git`


5. Добавете ни към вашето репо:  

    Settings -> Collaborators -> Add people (ivkaradzhova, Ivaylo-Valentinov)

\* А може и да не го правите и просто да си качвате ръчно файловете в репото си.
