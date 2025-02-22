public class Main{
    public static void main(String[] args)
    {
         Outer myObj=new Outer();
         myObj.show();
         Outer.Inner n=myObj.new Inner();
         n.show();


    }
    
}
class Outer
{
   public void show()
    {
        System.out.println("i am in outer class");
    }



     class Inner
    {
            void show()
            {
                System.out.println(" am in inner class");
            }

    }
}