public class Main {

    public static void main(String[] args) {
        //String [] formulae = {"-sun V -money V ice", "-money V ice V movie", "-movie V money","-money V -ice", "movie"};
        String[] formulae = {"-db", "da V dc", "-c V a", "a V b V c"};

        CNF testCNF = new CNF(formulae);
        testCNF.Solver();

    }
}
