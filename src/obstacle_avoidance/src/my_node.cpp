/*
 * Created By: Gareth Ellis
 * Created On: July 16th, 2016
 * Description: An example node that subscribes to a topic publishing strings,
 *              and re-publishes everything it receives to another topic with
 *              a "!" at the end
 */

#include <MyNode.h>



int main(int argc, char **argv){    //main program, executed from there
    // Setup your ROS node
    std::string node_name = "position";

    // Create an instance of your class, calls MyNode.cpp
    MyClass my_class(argc, argv, node_name);

    // Start up ros. This will continue to run until the node is killed
    ros::spin();

    // Once the node stops, return 0
    return 0;
}