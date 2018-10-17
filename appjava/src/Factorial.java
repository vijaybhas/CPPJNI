public class Factorial {
    private int num;
    public void SetNumber(int n) {

        num = n;
    }

    public int getNum(){
        return num;

    }

    public long computeFact(){

        int n = 1;
        for(int i=1; i<= getNum(); i++)
            n *= i;

        return n;
    }

    public static void main(String[] arg){

        Factorial f = new Factorial();
        f.SetNumber(5);
        long n = f.computeFact();
        System.out.print(n);
    }
}
