/*
 * Created By: Gareth Ellis
 * Created On: July 16th, 2016
 * Description: An example node that subscribes to a topic publishing strings,
 *              and re-publishes everything it receives to another topic with
 *              a "!" at the end
 */

#include <MyNode.h>

MyClass::MyClass(int argc, char **argv, std::subscriberCallBackstring node_name) {
    // Setup NodeHandles, Initializing node
    ros::init(argc, argv, node_name);
    ros::NodeHandle n;
    ros::NodeHandle private_nh("~");

    //TODELETE
    // Obtains character from the parameter server (or launch file), sets '!' as default
    std::string parameter_name = "my_node/character";
    std::string default_character;   //initialize the node= "!";
    SB_getParam(nh, parameter_name, suffix, default_character);

    // Setup Subscriber(s)
    std::string topic_to_subscribe_to = "subscribe_topic";  //figure out subscribe topic??
    int refresh_rate = 10;
    subscriber_laser = n.subscribe(topic_to_subscribe_to, refresh_rate,&MyClass::clbk_laser,this);

    // Setup Publisher(s)
    std::string topic = private_nh.resolveName("publish_topic");
    uint32_t queue_size = 1;
    my_publisher = private_nh.advertise<std_msgs::String>(topic, queue_size);
}

void MyClass::clbk_laser(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received message");
    //std::string input_string = msg->data.c_str();
    //std::string new_msg = addCharacterToString(input_string, suffix);
    republishMsg(new_msg);
}

std::string MyClass::addCharacterToString(std::string input_string, std::string suffix) {
    return input_string.append(suffix);
}

void MyClass::republishMsg(std::string msg_to_publish) {
    std_msgs::String string_to_publish;
    string_to_publish.data = msg_to_publish;
    my_publisher.publish(string_to_publish);
    ROS_INFO("Published message");
}
