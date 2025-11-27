class Solution {
    public String destCity(List<List<String>> paths) {
        for (List<String> path : paths) {
            String destination = path.get(1);
            boolean isStart = false;
            for (List<String> p : paths) {
                if (p.get(0).equals(destination)) {
                    isStart = true;
                    break;
                }
            }
            if (!isStart) return destination;
        }
        return "";

    }
}