/*
 * Created By: Gareth Ellis
 * Created On: July 16th, 2016
 * Description: A node that subscribes to a Laser scan message and re-publishes a twist message
 *              to direct the robot to its next point
 */

#include <MyNode.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msg/Twist.h>


//for ex to move rover, input should be geometry_msgs/Twist
//linear.x =5; angular.z = 0.4
//expected output coming back should be std_msgs/String
//"Received movement command: going forward at 5 m/s and turning left at 0.4 rad/s"


MyClass::MyClass(int argc, char **argv, std::subscriberCallBackstring node_name) {
    // Setup NodeHandles, Initializing node
    ros::init(argc, argv, node_name);
    ros::NodeHandle node;
    ros::NodeHandle private_node("~");     //????

    //TODELETE??
    // Obtains character from the parameter server (or launch file), sets '!' as default
    std::string parameter_name = "my_node/character";
    std::string default_character;   //initialize the node= "!";
    SB_getParam(node, parameter_name, suffix, default_character); //????


    // Setup Subscriber(s)
    //params: (topic to subscribe_to, refresh_rate, callback listener, this)
    ros::Subscriber scanSub = node.subscribe<sensor_msg::LaserScan>("/scan" 10,&MyClass::clbk_laser,this);  //listener for pose

    // Setup Publisher(s)
    //params (publish topic, uint32_t queue_size)
    ros:: Publisher twistPub = private_node.advertise<geometry_msgs::Twist>("geometry_msg/Twist", 10);  //can publish to any topic you want
    geometry_msgs::Twist msg;
  //  msg.linear.x = 0.5;
//    std::string topic = private_n.resolveName("publish_topic");
//    uint32_t queue_size = 1;
//    my_publisher = private_n.advertise<std_msgs::String>(topic, queue_size);

}

void MyClass::clbk_laser(const sensor_msgs::LaserScan::ConstPtr& msg) {       //callback in subscriber. move robot
    //scan->ranges[] are laser readings
    ROS_INFO("Received message");
    std::
    std::string input_string = msg->data.c_str();       //reads message
    //std::string new_msg = addCharacterToString(input_string, suffix);     //update movements?
    std::string next_move =
    republishMsg(next_move);        //call function to publish twist message
}

std::string MyClass::update_move(std::string input_string) {    //update move based on laserscan, called in callback, want params distance and angle?
    std string next_move;                                      //compute next move
    return next_move;
}

void MyClass::republishMsg(std::string msg_to_publish) {    //twist message?


    std_msgs::String string_to_publish;
    string_to_publish.data = msg_to_publish;
    my_publisher.publish(string_to_publish);

    ROS_INFO("Published message");

    //"Received movement command: going forward at 5 m/s and turning left at 0.4 rad/s"
}
