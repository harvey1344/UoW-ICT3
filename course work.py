def main():
    m1,m2,m3,m4=0,0,0,0
    sT,mT=0,0
    high, low= 0,100
    rM,average=0,0
    check=True
    while True:
       string= str(input("Please enter student mark: "))
       string=string.upper();
       if string=="Q":
           break
       elif string.isdigit():
           mark=int(string)
           rM+=mark
           m1,m2,m3,m4,sT,mT= markF(mark,m1,m2,m3,m4,sT,mT)
        
       else:
           print("That was not a number")
           continue
       high=highest(mark,high)
       low=lowest(mark,low)
       average=avCalc(rM,sT)
    pR=rate(m3,m4)
    fR=rate(m1,m2)

    stats(sT,average,pR,fR,high,low)
    hist(m1,m2,m3,m4)

    
    

    
      

def markF(x, m1,m2,m3,m4,sT,mT):
    if x in range(0,29):
        m1+=1
        sT+=1
        mT+=x
    elif x in range(30,39):
        m2+=1
        sT+=1
        mT=x
    elif x in range(40,69):
        m3+=1
        sT+=1
        mT+=x
    elif x in range (70,101):
        m4+=1
        sT+=1
        mT=+x
    else:
        print("Enter a number between 0-100")

    return m1,m2,m3,m4,sT,mT

def highest(x,y):
    if x>y:
        y=x
    else:
        pass
    return y

def lowest(x,y):
    if x<y:
        y=x
    else:
        pass
    return y

def avCalc(x,y):
    z=x/y
    return z

def rate(x,y):
    z=x+y
    return z

def stats(t,a,p,f,h,l):
    if t==0:
        pR=0
        fR=0
    else:
        pR=p/t*100
        fR=f/t*100
    print("\n\n\tStatistics\n".format())
    print("\tTotal marks inputted {}\n".format(t))
    print("\tAverage mark: {:.2f}\n".format(a))
    print("\tHighest mark: {}\n".format(h))
    print("\tLowest mark {}\n".format(l))
    print("\tTotal students passed: {}\n\tPass rate: {:.2f}\n".format(p,pR))
    print("\tTotal students failed {}\n\tFail rate: {:.2f}\n".format(f,fR))


def comp(a,b,c,d):
    #x=0
    if a>b:
        x=a
    else:
        x=b
    if c>x:
        x=c
    elif d>x:
        x=d
    return x

def hist(m1,m2,m3,m4):
    mVal=comp(m1,m2,m3,m4)
    height=mVal
    y="#"
    n= " "
    for i in range(mVal):
        if m1>=height:
            print("*", end='')
        else:
            print (" ", end='')
        if m2>=height:
            print("*", end='')
        else:
            print (" ", end='')
        if m3>=height:
            print("*", end='')
        else:
            print (" ", end='')
        if m4>=height:
            print("*")
        else:
            print(" ")
        height=height-1
        
            
main()






