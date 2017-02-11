# Enter your code here. Read input from STDIN. Print output to STDOUT
test=(int)(raw_input());
for i in range(0,test):
    string1=[]
    string2=[]
    value=[]
    count=0
    string1=raw_input();
    string2=raw_input();
    string1=string1+'z';
    string2=string2+'z';
    length=len(string1)+len(string2)-2;
    for j in range(0,length):
        if(string1<=string2):
            value.append(string1[0]);
            string1=string1[1:];
        else:
            value.append(string2[0]);
            string2=string2[1:];
    print "".join(value)
