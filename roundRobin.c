#include<stdio.h>

struct Process {
	int process_id;
	int arrival_time;
	int burst_time;
	int time_remaining;
};

void roundRobin(struct Process processes[], int n, int time_quantum) {
	
	int time = 0;
	int completed = 0;

	while(completed < n) {
		for(int i = 0; i<n; i++) {
			if(processes[i].arrival_time <= time && processes[i].time_remaining > 0){
				int execute_time = (processes[i].time_remaining < time_quantum ) ? processes[i].time_remaining : time_quantum;

				processes[i].time_remaining -= execute_time;
                		time += execute_time;

				printf("Process %d executed for %d units. Remaining time: %d\n", processes[i].process_id, execute_time, processes[i].time_remaining);

				if (processes[i].time_remaining == 0) {
                    			completed++;
                		}
			}
		}
	
	}
}

int main() {
	int n = 3;
	//printf("Enter the number of process:	");
	//scanf("%d", &n);
	struct Process processes[n];
	int tq = 2;
	//printf("Enter the time quantam of process:	");
	//scanf("%d", &time_quantam);
	processes[0] = (struct Process){1, 0, 4, 4};
    	processes[1] = (struct Process){2, 1, 3, 3};
    	processes[2] = (struct Process){3, 2, 2, 2};

	// for(int i = 0; i<n; i++){
	// 	printf("Enter the arrival time of the process:    ");
	// 	scanf("%d", &processes[i].arrival_time);
	// 	printf("Enter the burst time of the process:\t");
	// 	scanf("%d", &processes[i].burst_time);
	//  	processes[i].process_id = i+1;
	//  	processes[i].time_remaning = processes[i].burst_time;
	//  }
	
	printf("Round Robin Scheduling:\n");
    	roundRobin(processes, n, tq);

	return 0;
}
