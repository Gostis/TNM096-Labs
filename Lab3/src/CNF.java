import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.util.ArrayList;


public class CNF {

    ArrayList<Clause> clauseArrayList = new ArrayList<Clause>();

    // Adding the clauseString input to the clauseArrayList
    CNF(String[] clauseStringSet) {

        for (int i = 0; i < clauseStringSet.length; i++) {

            Clause tempClause = new Clause(clauseStringSet[i]);

            if (!tempClause.isEmpty()) {
                clauseArrayList.add(tempClause);
                //tempClause.Display();
            }
        }

    }

    public void Solver() {
        ArrayList<Clause> S;
        Clause C;
        ArrayList<Clause> KB = clauseArrayList;
        do {
            S = new ArrayList<Clause>();
            C = new Clause();
            for (int i = 0; i < KB.size() -1; i++) {
                for (int j = i + 1; j < KB.size(); j++) {
                    C = Resolution(KB.get(i), KB.get(j));
                    if (C != null){
                        S.add(C);
                    }
                }
            }

            System.out.println("This is S in do: ");
            for (int i = 0; i < S.size(); i++){
                S.get(i).Display();
            }

            System.out.println("KB before Incorporate: ");
            for (int i = 0; i < KB.size(); i++){
                KB.get(i).Display();
            }

            KB = Incorporate(S, KB);

            KB = removeDuplicates(KB);


            System.out.println("This is KB in do: ");
            for (int i = 0; i < KB.size(); i++){
                KB.get(i).Display();
            }

        }while (C != null && !C.isEmpty());

        // Solved
        System.out.println("This is KB!");
        for (int i = 0; i < KB.size(); i++){
            KB.get(i).Display();
        }



    }

    public Clause Resolution(Clause A, Clause B) {
        Clause C = new Clause();

        String literalApBn = "";
        String literalAnBp = "";
        for (int i = 0; i < A.positiveAlist.size(); i++) {

            if (B.negativeAlist.contains(A.positiveAlist.get(i))) {

                literalApBn = literalApBn.concat(A.positiveAlist.get(i));
            }

        }

        for (int i = 0; i < A.negativeAlist.size(); i++) {

            if (B.positiveAlist.contains(A.negativeAlist.get(i))) {

                literalAnBp = literalAnBp.concat(A.negativeAlist.get(i));
            }


        }


        if (literalApBn.equals("") && literalAnBp.equals("")) {
            System.out.println("Resolution false");
            return null;
        }

        if (!literalApBn.equals("") || !literalAnBp.equals("")) {

            for (int i = 0; i < A.positiveAlist.size(); i++) {
                if (!A.positiveAlist.get(i).equals(literalApBn) && !C.positiveAlist.contains(A.positiveAlist.get(i))) {

                    C.positiveAlist.add(A.positiveAlist.get(i));
                }
            }

            for (int i = 0; i < A.negativeAlist.size(); i++) {
                if (!A.negativeAlist.get(i).equals(literalAnBp) && !C.negativeAlist.contains(A.negativeAlist.get(i))) {

                    C.negativeAlist.add(A.negativeAlist.get(i));
                }
            }

            for (int i = 0; i < B.positiveAlist.size(); i++) {
                if (!B.positiveAlist.get(i).equals(literalAnBp) && !C.positiveAlist.contains(B.positiveAlist.get(i))) {

                    C.positiveAlist.add(B.positiveAlist.get(i));
                }
            }

            for (int i = 0; i < B.negativeAlist.size(); i++) {
                if (!B.negativeAlist.get(i).equals(literalApBn) && !C.negativeAlist.contains(B.negativeAlist.get(i))) {

                    C.negativeAlist.add(B.negativeAlist.get(i));
                }
            }
        }

        if (!literalAnBp.equals("") && !literalApBn.equals("")) {
            System.out.println("Resolution false because of intersect");
            return null;
        }

        C.RemoveDuplicates();
        System.out.println("Result of resolution: ");
        C.Display();

        return C;
    }

    public ArrayList<Clause> Incorporate(ArrayList<Clause> S, ArrayList<Clause> KB){
        for (int i = 0; i < S.size(); i++){
            KB = Incorporate_Clause(S.get(i), KB);
        }

        return KB;
    }

    public ArrayList<Clause> Incorporate_Clause(Clause A, ArrayList<Clause> KB){

        for (int i = 0; i < KB.size(); i++){
            if (KB.get(i).equals(A)){
                return KB;
            }
            else if(A.isSubset(KB.get(i))){

                KB.get(i).negativeAlist = A.negativeAlist;
                KB.get(i).positiveAlist = A.positiveAlist;
            }

        }

        return KB;
    }

    public ArrayList<Clause> removeDuplicates(ArrayList<Clause> KB){
        ArrayList<Clause> tempKB = KB;

        for (int i = 0; i < KB.size() -1; i++){
            for (int j = i + 1; j < tempKB.size(); j++){
                if (KB.get(i).equals(tempKB.get(j))){
                    KB.remove(i);
                }
            }
        }
        return KB;
    }
}
