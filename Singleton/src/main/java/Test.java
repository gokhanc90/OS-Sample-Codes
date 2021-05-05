
public class Test implements Runnable{

    public static boolean flag;

    public static void main(String[] args)  {

        for (int i=0; i<100; i++){
            new Thread(new Test()).start();
        }
    }

    @Override
    public void run() {
        if(flag)
            System.out.println(Singleton.getInstance().hashCode());
        else
            System.out.println(Singleton.getInstanceWithoutSynchronized().hashCode());
    }
}
