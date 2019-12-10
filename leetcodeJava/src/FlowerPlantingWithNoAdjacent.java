import java.util.*;

public class FlowerPlantingWithNoAdjacent {

    public static int[] gardenNoAdj(int N, int[][] paths) {
        int[] result = new int[N];
        int[] to_give = {1, 2, 3, 4};

        Graph graph = new Graph();
        for(int i = 1; i <= N; i++) {
            Vertex vertex = new Vertex(i);
            graph.addVertex(vertex);
        }

        for (int i = 0; i < paths.length; i++) {
            graph.addEdge(graph.vertices.get(paths[i][0]-1), graph.vertices.get(paths[i][1]-1));
        }



        for(int i =0; i < graph.vertices.size(); i++){
            // start dfs here
            Vertex first = graph.vertices.get(i);
            // first.visited = true;
            ArrayList<Integer> toChoose = new ArrayList<>();
            for(int x = 0; x < 4; x++){
                toChoose.add(x+1);
            }
            for(int a=0; a < first.neighbors.size(); a++){
                Vertex neighVer = first.neighbors.get(a);
                if(toChoose.contains(neighVer.flower)){
                    toChoose.remove(neighVer.flower);
                }
            }
            depthFirstSearch(first, toChoose);
        }

        for(int i = 0; i < graph.vertices.size(); i++) {
            Vertex v = graph.vertices.get(i);
            result[i] = v.flower;
        }
        return result;

    }

    public static void depthFirstSearch(Vertex vertex, ArrayList<Integer> list){
        // boolean[] visited = new boolean[N];
       // Vertex first = graph.vertices.get(0);
        //first.visited = true;
       // ArrayList<Integer> toChoose = new ArrayList<>();
       // for(int i = 0; i < toChoose.size(); i++){
       //     toChoose.add(i+1);
       // }
        if(vertex.visited){
            return;
        }
        vertex.visited = true;

        vertex.flower = list.get(0);
        list.remove(0);
        for(int i=0; i < vertex.neighbors.size(); i++){
            Vertex curVertex = vertex.neighbors.get(i);
            if(!curVertex.visited){
                depthFirstSearch(curVertex, list);
            }
        }

    }

    public void depthFirstSearchHelper(Vertex ver, int[] toChoose){

    }


    static class Vertex {
        int flower;
        boolean visited;
        List<Vertex> neighbors;
        int data;

        public Vertex(int data) {
            this.data = data;
            this.flower = 0;
            this.visited = false;
            this.neighbors = new ArrayList<>();
        }
    }


    static class Graph {
        ArrayList<Vertex> vertices;

        public Graph() {

            vertices = new ArrayList<>();
        }

        public void addVertex(Vertex v){
            vertices.add(v);
        }
        public void addEdge(Vertex a, Vertex b){
            // this is bi-directional
            a.neighbors.add(b);
            b.neighbors.add(a);
        }
    }

    public static void main(String[] args) {
       int N = 5;
       int[][] paths = {{4,1},{4,2},{4,3},{2,5},{1,2},{1,5}};
        int[] r = gardenNoAdj(N, paths);
        System.out.println(Arrays.toString(r));

    }
}
