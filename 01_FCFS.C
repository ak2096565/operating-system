#include<stdio.h>

void FCFS(int n,int pid[],int at[],int bt[]){
   int ct[n];
   int tat[n];
   int wt[n];
   float total_wt=0;
   float total_tat=0;


   //sorting the arrival time, process id ,brust time,

   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-1-i;j++){
      if(at[j]>at[j+1]){
         int temp,temp1,temp2;

         // sorting arriva time

         temp=at[j];
         at[j]=at[j+1];
         at[j+1]=temp;

         //sorting process id

         temp1=pid[j];
         pid[j]=pid[j+1];
         pid[j+1]=temp1;

         //sorting brust time

         temp2=bt[j];
         bt[j]=bt[j+1];
         bt[j+1]=temp2;

         

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
   printf("\navarage turnaround time = %f ",total_tat/n);
   
}

int main(){
   int n;
   printf("enter the number of process : ");
   scanf("%d",&n);
   int pid[n];
   int at[n];
   int bt[n];
   // for(int i=0;i<n;i++){
   //    pid[i]=1+1;
   //    printf("enter arrival time of P%d : ",i+1);
   //    scanf("%d",&at[i]);
   //    printf("enter burst time of P%d : ",i);
   //    scanf("%d",&bt[i]);
   // }
   for(int i=0;i<n;i++){
      pid[i]=i+1;
      printf("enter arrival time of P%d : ",i+1);
      scanf("%d",&at[i]);
   }
   for(int i=0;i<n;i++){
      printf("enter brust time time of P%d : ",i+1);
      scanf("%d",&bt[i]);
   }
    FCFS(n,pid,at,bt);
   


}