import rclpy
import numpy as np
import matplotlib.pyplot as plt
from rclpy.node import Node

class PlotData(Node):
    def __init__(self):
        super().__init__("data_plot_node")
        self.get_logger().info("data_plot_node created")

def main():
    rclpy.init()
    plot_node = PlotData()

    try:
        rclpy.spin(plot_node)
    except KeyboardInterrupt:
        print("用户关闭")
    finally:
        rclpy.shutdown() # 防止按ctrl + c时无法关闭


if __name__ == '__main__':
    main()
