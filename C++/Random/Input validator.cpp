double InputValidate(double num)
{
    while(!(cin>>num)||num<0){
        cout<<"Error ! a value above 0 must be entered. ";
        cin.clear();
        cin.ignore(1200,'\n');
    }
        return num;
}
    