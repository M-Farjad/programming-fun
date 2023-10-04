#first EXERCISE
marks=int(input("what is ur name: "))
do{
    flag=false
    per=int(input("What is ur per: "))
    if per>90:
        print('A')
    elif per>80:
        print('B')
    elif per>70:
        print('C')
    elif per>60:
        print('D')
    elif per>50:
        print('E')
    elif per>=0:
        print('F')
    else:
    {
        print("Enter Valid percentage")
        flag=true
    }
}while(!(flag))