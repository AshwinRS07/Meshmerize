void mazeEnd(void)
{
  pathF=Optimize(pathI);
}


void ledBlink(void)
{
  
}

String Optimize(String path)
{
  int OptpathIndex,pathIndex,Optflag=0;
  PathLen=path.length();
  String Optpath="";
  for(pathIndex=0,OptpathIndex=0;pathIndex<PathLen;pathIndex++)         //Traversal
  {
     Serial.println(Optpath);
     if(pathIndex!=0 || pathIndex!=PathLen-1){
     if(path.charAt(pathIndex-1)=='U' && path.charAt(pathIndex+1)=='U')      //For alternating U occurences
    {
      for(i=pathIndex+1;i<PathLen;i++)
        {
          Optpath += path.charAt(i);
        }
      break;
    }

    
    if(((path.charAt(pathIndex+1)!='U') && (path.charAt(pathIndex-1)!='U')) && (path.charAt(pathIndex)!='U'))       //Normal cases
    {
      Optpath+=path.charAt(pathIndex);
      OptpathIndex++;
    }
    else if(path.charAt(pathIndex) == 'U')
    {
       if(path.charAt(pathIndex-1)=='L' && path.charAt(pathIndex+1)=='L')
       {
        Optpath+='S';
        OptpathIndex++;
       }
       else if(path.charAt(pathIndex-1)=='L' && path.charAt(pathIndex+1)=='S')
       {
        Optpath+='R';
        OptpathIndex++;
       }
       else if(path.charAt(pathIndex-1)=='S' && path.charAt(pathIndex+1)=='L')
       {
        Optpath+='R';
        OptpathIndex++;
       }
       else
       {
        Optpath+='U';
        OptpathIndex++;
       }
    }
  }
  }
  for(i=0;i<Optpath.length();i++)                             //Recall function if Dead ends exist
  {
    if(Optpath.charAt(i)=='U')
    {
      Optpath=Optimize(Optpath);
      break;
    }
  }
  return Optpath;
}
