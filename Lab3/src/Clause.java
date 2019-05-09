import java.util.ArrayList;


public class Clause {

    public ArrayList<String> negativeAlist = new ArrayList<String>();
    public ArrayList<String> positiveAlist = new ArrayList<String>();

    Clause(){

    }


    // initialising the clause by adding the literals to the positive and negative sets.
    Clause(String formulae){
        //System.out.println(formulae);
        formulae = formulae.replaceAll(" ", "");
        formulae = formulae.replaceAll("V", " ");

        //System.out.println(formulae);
        String [] formulaeArray = formulae.split(" ");

        for (int i = 0; i < formulaeArray.length; i++){

            if (formulaeArray[i].contains("-"))
            {
                formulaeArray[i] = formulaeArray[i].replace("-", "");
                negativeAlist.add(formulaeArray[i]);
            }
            else {
                positiveAlist.add(formulaeArray[i]);
            }
        }
        /*System.out.println("positiveAlist " + positiveAlist.size());
        System.out.println("negativeAlist " + negativeAlist.size());*/
    }

    // Removing duplicates
    public void RemoveDuplicates(){

        for (int i = 0; i < negativeAlist.size(); i++){
            for (int j = 0; j < positiveAlist.size(); j++){
                if (negativeAlist.get(i).equals(positiveAlist.get(j))){
                    negativeAlist.remove(i);
                    positiveAlist.remove(j);
                }
            }
        }
    }

    public boolean isSubset(Clause tempClause){

        //System.out.println("isSubset");
        for (int i = 0; i < this.positiveAlist.size(); i++){
            if (!tempClause.positiveAlist.contains(this.positiveAlist.get(i))){
                return false;
            }
        }

        for (int i = 0; i < this.negativeAlist.size(); i++){
            if (!tempClause.negativeAlist.contains(this.negativeAlist.get(i))){
                return false;
            }
        }

        return true;



    }

    // Checking if the clause is empty
public boolean isEmpty(){
    if (negativeAlist.isEmpty() && positiveAlist.isEmpty())
        return true;
    else
        return false;
}


// Display function for the clause
public void Display(){
    System.out.printf("[");

    if (positiveAlist.size() == 0){

    }else{
        for (int i = 0; i < positiveAlist.size(); i++) {
            if (positiveAlist.size() == 1){
                System.out.printf(positiveAlist.get(i));

                if (negativeAlist.size() > 0){
                    System.out.printf(" V ");
                }

            }else{
                if (i + 1 == positiveAlist.size()){
                    System.out.printf(positiveAlist.get(i));

                    if (negativeAlist.size() > 0){
                        System.out.printf(" V ");
                    }
                }else
                    System.out.printf(positiveAlist.get(i) + " V ");
            }
        }
    }

    //System.out.println("negativeAlist.size()" + negativeAlist.size());
    if (negativeAlist.size() == 0) {
        System.out.println("]");

    }else{
        for (int i = 0; i < negativeAlist.size(); i++) {

            if (negativeAlist.size() == 1)
            {
                System.out.printf("-" + negativeAlist.get(i) + "] \n");

            }else{
                if (i + 2 > negativeAlist.size()){
                    System.out.printf("-" + negativeAlist.get(i) + "] \n");
                }else
                    System.out.printf("-" + negativeAlist.get(i) + " V ");
            }

        }
    }


}

@Override
public boolean equals(Object tempObj){
        //System.out.println("EQUALS");
        if (tempObj == this){
            return true;
        }

        if (tempObj == null) {
            return false;
        }

        if (getClass() != tempObj.getClass()){
            return false;
        }

        Clause tempClause = (Clause) tempObj;

        if (negativeAlist == null){
            if (tempClause.negativeAlist != null){
                return false;
            }
        }else if (!negativeAlist.equals(tempClause.negativeAlist)){
            return false;
        }

    if (positiveAlist == null){
        if (tempClause.positiveAlist != null){
            return false;
        }
    }else if (!positiveAlist.equals(tempClause.positiveAlist)){
        return false;
    }

    return true;
}

public boolean PosNegIntersect(){
        if (this.positiveAlist.size() > this.negativeAlist.size()){
            for (int i = 0; i < this.positiveAlist.size(); i++){
                if (this.negativeAlist.contains(this.positiveAlist.get(i))){
                    return true;
                }
            }
            return false;
        }else{
            for (int i = 0; i < this.negativeAlist.size(); i++){
                if (this.positiveAlist.contains(this.negativeAlist.get(i))){
                    return true;
                }
            }
            return false;
        }


}

}

