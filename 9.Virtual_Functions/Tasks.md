# 25-ти април 2023 г.

## 1. задача
Реализирайте следните класове:
- **Animal**, който има следните характеристики:
    - член-данни - име и вид
    - чисто виртуален метод **talk()**
- **Cat** - наследява **Animal** и предефинира функцията **talk()**
- **Dog** - наследява **Animal** и предефинира функцията **talk()**

Създайте хетерогенен масив, който да съдържа различни обекти и на всеки обект извикайте метода **talk()**.


## 2. задача
(Задачата разширява [2-рата задачата от упражнение 8](https://github.com/ivkaradzhova/FMI_OOP_2022-23/blob/master/8.Templates_And_Inheritance/Tasks.md#2-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0) )

а) Създайте клас за проектите, който да съдържа информация за:
1. **име**
2. **сложност**, число от 1 до 10

Добавете възможност ИТ специалистите (**програмисти** и **QA**) да могат да участват в повече от един проект.

б) Тъй като нашата ИТ фирма иска да оцени усилията, които служителите полагат, всяка година увеличава заплатата им спрямо работата, която са свършили.   
Имплемнетирайте функция **annual_raise** за всяка една от ролите, която калкулира и увеличава заплатата на съответния служител по следния начин:
1. Увеличението на заплатата при **програмистите** е:
    - **6%** ако средната сложност на проектите, по които работят е **от 1 до 4**
    - **12%** ако средната сложност на проектите, по които работят е **от 5 до 7**
    - **15%** ако средната сложност на проектите, по които работят е **от 8 до 10**

2. Увеличението на заплатата при **manual QA** е:
    - **5%** ако броят проекти, по които работят е **1**
    - **10%** ако броят проекти, по които работят е **2 или 3**
    - **15%** ако броят проекти, по които работят е **над 3**

3. Увеличението на заплатата при **autimation QA** е:
    - **5%** ако средната сложност на проектите, по които работят е **от 1 до 4**
    - **10%** ако средната сложност на проектите, по които работят е **от 5 до 7**
    - **15%** ако средната сложност на проектите, по които работят е **от 8 до 10**

4. Увеличението на заплатата при **мениджърите** е:
    - **6%** ако управляват **от 1 до 10 души** 
    - **12%** ако управляват **от 11 до 15 души** 
    - **15%** ако управляват **над 15** 

в) Създайте клас System, който да съдържа следната информация за фирмата:
- годишен бюджет
- масив от служители
- масив от проекти, които разработва

Имплементирайте метод **annual_raises**, който увеличава заплатата на всеки от служителите, които работят в компанията, и намаля съответно годишния бюджет.