#include<stdio.h>
void swap(int a,int b){
   int temp;
   temp=a;
   a=b;
   b=temp;
   printf("%d %d",a,b);
}
void FCFS(int n,int pid[],int at[],int bt[]){
   int ct[n];
   int tat[n];
   int wt[n];
   float total_wt=0;
   float total_tat=0;


   //sorting the arrival time, process id ,brust time,

   for(int i=0;i<n;i++){
      for(int j=0;j<n-1-i;i++){
      if(at[j]>at[j+1]){
         swap(at[j],at[j+1]);
         swap(pid[j],pid[j+1]);
         swap(bt[j],bt[j+1]);

      }
      }
   }
   //calculating complition time

   ct[0]=at[0]+bt[0];
   for(int i=1;i<n;i++){
      if(ct[i-1]<at[i]){
         ct[i]=at[i]+bt[i];
      }
      else{
         ct[i]=ct[i-1]+bt[i];
      }
   }
   // calculating turnaround time,waiting time
   for(int i=0;i<n;i++){
      tat[i]=ct[i]-at[i];
      wt[i]=tat[i]-bt[i];
      total_wt+=wt[i];
      total_tat+=tat[i];
       
   }
   printf("Pid\tAt\tBt\tCt\tTaT\tWT\n");
   for(int i=0;i<n;i++){
      printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);

   }
   printf("\navarage waiting time = %f ",total_wt/n);
   printf("\navarage waiting time = %f ",total_tat/n);
   
}

int main(){
   int n;
   printf("enter the number of process : ");
   scanf("%d",&n);
   int pid[n];
   int at[n];
   int bt[n];
   // for(int i=0;i<n;i++){
   //    pid[i]=i;
   //    printf("enter arrival time of P%d : ",i);
   //    scanf("%d",&at[i]);
   //    printf("enter burst time of P%d : ",i);
   //    scanf("%d",&bt[i]);
   // }
   for(int i=0;i<n;i++){
      pid[i]=i;
      printf("enter arrival time of P%d : ",i);
      scanf("%d",&at[i]);
   }
   for(int i=0;i<n;i++){
      printf("enter brust time time of P%d : ",i);
      scanf("%d",&bt[i]);
   }
    FCFS(n,pid,at,bt);
   


}