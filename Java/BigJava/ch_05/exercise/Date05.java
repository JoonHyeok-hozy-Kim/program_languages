package exercise;

public class Date05 {
    int month;
    int date;

    private class Node{
        String val;
        Node next;

        public Node(String val, Node next){
            this.val = val;
            this.next = next;
        }

        public void setNext(Node next){
            this.next = next;
        }
    }

    public Date05(int month, int date){
        this.month = month;
        this.date = date;
    }

    public void getSeason(){
        Node n4 = new Node("Winter", null);
        Node n3 = new Node("Fall", n4);
        Node n2 = new Node("Summer", n3);
        Node n1 = new Node("Spring", n2);
        n4.setNext(n1);

        Node curr;
        if (this.month >= 1 || this.month <= 3){
            curr = n4;
        } else if (this.month >= 4 || this.month <= 6){
            curr = n1;
        } else if (this.month >= 7 || this.month <= 9){
            curr = n2;
        } else {
            curr = n3;
        }

        if (this.month % 3 == 0 && this.date >= 21){
            curr = curr.next;
        }

        // return curr.val;
        System.out.println(curr.val);
    }
}
