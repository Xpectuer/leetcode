class Dijkestra {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    	//初始化图
        int[][] graph = new int[n][n];
        //填入起点和终点作为下标，填入成本，构成权重矩阵
        for (int[] flight: flights)
            graph[flight[0]][flight[1]] = flight[2];

        //创建散列表。。。？
        Map<Integer, Integer> best = new HashMap();
        //优先级队列存放找到  一跳 最小路径
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        //抵达原点的成本以及插入优先级队列
        pq.offer(new int[]{0, 0, src});


        while (!pq.isEmpty()) {
        	//返回头部元素，即从起点开始的最短边
            int[] info = pq.poll();
            
            //记录成本 cost=info[0]
            //将抵达的位置 place=info[2]
            //跳数 k=info[1]

            int cost = info[0], k = info[1], place = info[2];

            //排除k跳以上的情况 ｜｜ 比较成本，若高于散列表内成本，则跳过？
            /**
            	*	TODO:（k*1000没看懂）
            */
            if (k > K+1 || cost > best.getOrDefault(k * 1000 + place, Integer.MAX_VALUE))
                continue;
            //若将要抵达的位置等于目的地 则返回
            if (place == dst)
                return cost;

            //遍历当前邻接节点
            for (int nei = 0; nei < n; ++nei) 

            	if (graph[place][nei] > 0) {
            		//计算出边权重
                int newcost = cost + graph[place][nei];
                //比较出边权重与当前已有的路径价格,若比已有价格低，则置入散列表和优先级队列
                if (newcost < best.getOrDefault((k+1) * 1000 + nei, Integer.MAX_VALUE)) {

                    pq.offer(new int[]{newcost, k+1, nei});
                    best.put((k+1) * 1000 + nei, newcost);
                }
            }
        }
        //找不到边
        return -1;
    }
}

