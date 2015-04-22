import java.lang.*;
import java.io.*;


class MatMulti extends Thread
{
        static int in1[][];
        static int in2[][];
        static int out[][];
        static int n=2;
        int row;
        MatMulti(int i)
        {
                row=i;
                this.start();
        }
        public void run()
        {
                int i,j;
                for(i=0;i<n;i++)
                {
                        out[row][i]=0;
                        for(j=0;j<n;j++)
                                out[row][i]=out[row][i]+in1[row][j]*in2[j][i];
                }
        }
        public static void main(String args[])
        {
                int i,j;
                BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
                System.out.print("Enter the order of Matrix : ");
                try
                {
                        n=Integer.parseInt(br.readLine());
                }catch(Exception e){}
                in1=new int[n][n];
                in2=new int[n][n];
                out=new int[n][n];
                System.out.println("Enter the First Matrix : ");
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                try
                                {
                                        in1[i][j]=Integer.parseInt(br.readLine());
                                }catch(Exception e){}
                        }
                }
                System.out.println("Enter the Second Matrix : ");
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                try
                                {
                                        in2[i][j]=Integer.parseInt(br.readLine());
                                }catch(Exception e){}
                        }
                }
                MatMulti mat[]=new MatMulti[n];
                for(i=0;i<n;i++)
                        mat[i]=new MatMulti(i);
                try
                {
                        for(i=0;i<n;i++)
                                mat[i].join();
                }catch(Exception e){
			e.printStackTarce();
		}
                System.out.println("OUTPUT :");
                for(i=0;i<n;i++)
                        for(j=0;j<n;j++)
                                System.out.println(out[i][j]);
        }
}

