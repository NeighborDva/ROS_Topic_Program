#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float32.h"
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
 /*
void chatterCallback1(const std_msgs::Int16::ConstPtr& msg)
{
  ROS_INFO("I heard Int16[%d]", msg->data);
}*/
/*
void chatterCallback2(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("I heard Int8[%d]", msg->data);
}
*/

void chatterCallback3(const std_msgs::Float32::ConstPtr& msg)
{
  ROS_INFO("I heard Float32[%f]", msg->data);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "listener");

  
   
  ros::NodeHandle n;

 
  //ros::Subscriber sub1 = n.subscribe("/numbers", 10, chatterCallback1);
//ros::Subscriber sub2 = n.subscribe("/numbers", 10, chatterCallback2);
  ros::Subscriber sub3 = n.subscribe("/numbers", 10, chatterCallback3);

  
  ros::spin();

  return 0;
}
