#include <stdio.h>
#include <stdlib.h>

#include "ros/ros.h"

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include <vector>
#include "std_msgs/Int32MultiArray.h"
using namespace std;
int main(int argc, char **argv)
{
    

	ros::init(argc, argv, "publish");

	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<std_msgs::Int32MultiArray>("chatter", 100);
int count=1;
	while (ros::ok())
	{
		std_msgs::Int32MultiArray array;
		//Clear array
		array.data.clear();
		//for loop, pushing data in the size of the array
		for (int i = 0; i < 90; i++)
		{
			
			//assign array a random number between 0 and 255.
			int num=0;
			num=rand()%255;
			ROS_INFO("num:%d \n",num);
			array.data.push_back(num);
			ROS_INFO("data[%d]=%d\n",i,array.data[i]);
		}
		
		//Publish array
		pub.publish(array);
		//Let the world know
		ROS_INFO("I published something! %d",count);
		count++;
		//Do this.
		ros::spinOnce();
		//Added a delay so not to spam
		sleep(2);
	}

}
