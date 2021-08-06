#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float32.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  //ros::Publisher chatter_pub1 = n.advertise<std_msgs::Int16>("/numbers", 10);
    //ros::Publisher chatter_pub2 = n.advertise<std_msgs::Int8>("/numbers", 10);
      ros::Publisher chatter_pub3 = n.advertise<std_msgs::Float32>("/numbers", 10);
        

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int num1,num2 = 0;
  float num3=0.0;
  
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    //std_msgs::Int16 msg1;
    //std_msgs::Int8 msg2;
      std_msgs::Float32 msg3;

   // msg1.data = num1;
    //msg2.data = num2;
    msg3.data=num3;
    
    ROS_INFO("Float32:%f ", msg3.data);

   
    //chatter_pub1.publish(msg1);
     // chatter_pub2.publish(msg2);   
      chatter_pub3.publish(msg3);

    ros::spinOnce();

    loop_rate.sleep();
    ++num1;
    ++num2;
    ++num3;
  }


  return 0;
}

