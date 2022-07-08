void bubbleSort(int v[], int n){
	int i, ordinato = 0;
	
	while (n>1 && !ordinato){
		ordinato = 1;
		for (i=0; i<n-1; i++)
			if (v[i]>v[i+1]) {
				scambia(&v[i],&v[i+1]);
				ordinato = 0;
			}
		n--;
	}
}
