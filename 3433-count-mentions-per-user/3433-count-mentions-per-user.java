import java.util.*;

class Solution {
    static class Event {
        String type;
        int time;
        String payload;
        Event(String t, int ti, String p) {
            type = t;
            time = ti;
            payload = p;
        }
    }

    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        int[] mentions = new int[numberOfUsers];
        boolean[] online = new boolean[numberOfUsers];
        Arrays.fill(online, true);

        // Parse events into list and sort by timestamp
        List<Event> list = new ArrayList<>();
        for (List<String> e : events) {
            list.add(new Event(e.get(0), Integer.parseInt(e.get(1)), e.get(2)));
        }
        list.sort((a, b) -> a.time - b.time);

        // Use TreeMap for scheduled returns so we can poll smallest return times efficiently
        TreeMap<Integer, List<Integer>> returns = new TreeMap<>();

        int i = 0, n = list.size();
        while (i < n) {
            int t = list.get(i).time;

            // Process all scheduled returns with returnTime <= t
            while (!returns.isEmpty()) {
                Map.Entry<Integer, List<Integer>> first = returns.firstEntry();
                if (first.getKey() <= t) {
                    for (int u : first.getValue()) online[u] = true;
                    returns.pollFirstEntry();
                } else break;
            }

            // gather all events at time t
            int j = i;
            while (j < n && list.get(j).time == t) j++;

            // First apply all OFFLINE events at t
            for (int k = i; k < j; k++) {
                Event e = list.get(k);
                if (e.type.equals("OFFLINE")) {
                    int user = Integer.parseInt(e.payload);
                    online[user] = false;
                    int ret = t + 60;
                    returns.computeIfAbsent(ret, x -> new ArrayList<>()).add(user);
                }
            }

            // Then process all MESSAGE events at t
            for (int k = i; k < j; k++) {
                Event e = list.get(k);
                if (!e.type.equals("MESSAGE")) continue;
                String msg = e.payload;

                if (msg.equals("ALL")) {
                    for (int u = 0; u < numberOfUsers; u++) mentions[u]++;
                } else if (msg.equals("HERE")) {
                    for (int u = 0; u < numberOfUsers; u++)
                        if (online[u]) mentions[u]++;
                } else {
                    String[] tokens = msg.split(" ");
                    for (String tok : tokens) {
                        if (tok.startsWith("id")) {
                            int id = Integer.parseInt(tok.substring(2));
                            mentions[id]++;
                        }
                    }
                }
            }

            i = j;
        }

        return mentions;
    }
}
