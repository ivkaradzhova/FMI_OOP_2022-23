# 9-ти май 2023 г.

# 1. задача
Реализирайте темплейтен клас MyVector, който да пази динамично преоразмеряващ се масив от еднакви обекти и има методи за:  
- добавяне на нов елемент - addElement(T element);
- предефиниране на оператора за достъп до елемент [] ;
- прилагане на подадена функция върху всичките му елементи - apply(R (*func) (T&)), където apply също е темплейтна функция и приема като параметър указател към функция, която връща стойности от тип R и приема стойности от типа на масива - Т.

Пример за последната подточка:  
при масив от int - {1, 2, 3, 4}

```
double addOne(double& a) {
    return ++a;
}

int main() {
    MyVector<double> arr;

    arr.addElement(5.5);
    arr.addElement(5.7);
    arr.addElement(4.2);
    arr.addElement(9.3);

    arr.apply(addOne);

    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
```
Примера трябва да изведе:
```
6.5 6.7 5.2 10.3
```

# 2. задача
Да се реализира абстрактен базов клас Question, който описва следните операции върху въпрос от тест:

- **ask**, която извежда въпроса и въвежда негов отговор;
- **grade**, която оценява въпрос и връща броя точки.

Да се реализират следните видове въпроси:

- **YesNoQuestion**, който описва въпрос с два възможни отговора: да или не. При конструиране се задават текст, точки и верен отговор. Въпросът дава 0 т. при грешен и пълен брой точки при верен отговор.
- **MultipleChoice**, който описва въпрос с няколко възможни отговори, от които някои са верни. При конструиране се задават текст, точки x, възможни и верни отговори. Всеки правилно посочен отговор добавя x точки, а всеки погрешно посочен отговор отнема x точки.
- **OpenQuestion**, който описва въпрос със свободен текст. При конструиране се задават текст и брой точки. При оценяване се извеждат въпроса и отговора и се въвежда оценка в проценти. Ако отговор не е даден, въпросът автоматично се оценява с 0 т.

Да се реализира клас Test, представящ тест с въпроси от всякакъв вид. Да се реализират функциите:

- **addQuestion**, която добавя нов въпрос към теста;
- **doTest**, която задава всички въпроси подред и събира отговорите им;
- **gradeTest**, която оценява теста и връща броя събрани точки.