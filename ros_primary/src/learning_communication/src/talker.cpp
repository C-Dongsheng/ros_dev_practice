
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
	// ROS节点初始化,talker为节点名称
	ros::init(argc,argv,"talker");

	// 创建节点句柄
	ros::NodeHandle n;

	// 创建一个Publisher,topic名为chatter
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);

	// 设置循环频率
	ros::Rate loop_rate(10);

	int count = 0;
	// ros循环部分
	while (ros::ok())
	{
		// 初始化std_msgs::String类型的消息
		std_msgs::String msg;
		// 字符串和数字的连接
		// 1）C++11新特性，to_string()方法
		// std::string ss;
		// ss = "Hello World " + std::to_string(count);
		// msg.data = ss;
		// 2）C++风格
		std::ostringstream oss;
		oss << "Hello World " << count;
		msg.data = oss.str();

		// 发布消息
		chatter_pub.publish(msg);
		ROS_INFO("%s",msg.data.c_str());

		// 按照循环频率延时
		loop_rate.sleep();

		count++;
	}
	return 0;
	
}