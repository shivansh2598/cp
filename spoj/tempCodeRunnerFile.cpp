bool check=false;
    if(x==1)
    return 1;
   for(int j=2;j<sqrt(x)+1;j++)
   {
       int k;
       float k1;
       k1=float(log(x))/log(j);
       k=k1;
       if(k==k1&&k>1){
       return 1;
       }
   }

   return 0;