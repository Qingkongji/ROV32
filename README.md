# 水下无人机航控系统 ROV32 
![](https://img.shields.io/badge/build-passing-green.svg)        ![](https://img.shields.io/badge/ROV--build-v0.1.1-blue.svg)        ![](https://img.shields.io/badge/status-open-green.svg)   
哈尔滨工业大学无人机创新实验室水下无人机项目——`水下无人机航控系统`    
Harbin Institute of Technology Unmanned Aerial Vehicel Laboratory ROV project-`ROV Control system`

|Maintainer|纪相存|段士奇|郑晓丰（负责人）
|---|---|---|---
|E-mail|qingkong.ji@qq.com|815832177@qq.com|494939701@qq.com
|github|https://github.com/Qingkongji|https://github.com/HaskiDuan|https://github.com/TosakaR

****
## 目录 Table of Contents
<!--ts-->
* [介绍 Introduction](#介绍-introduction)  
* [开发环境 Development Environment](#开发环境-development-environment) 
* [分电板 Electric transfer plate](#分电板-eletric-transfer-plate)
    * 分电板概述 Introduction of electric transfer plate
* [地面站主板 Ground station board](#地面站主板-ground-station-board)
    * 地面站主板概述 Introduction of ground station board
* [控制器主板 Controller main board](#控制器主板-controller-main-board)
    * 控制器主板概述 Introduction of controller main board
<!--te-->

***

## 介绍 Introduction
该仓库为哈尔滨工业大学无人机创新实验室水下无人机项目的航控系统仓库，包含了运行在水下无人机控制器主板的航控系统STM32工程。  
This repository is the HIT UAV-Lab Remotely operated vehicle(ROV) motion control system repository, it includes the STM32 projects for the motion control system running on the ROV controller.

## 开发环境 Development Environment
水下无人机航控系统的开发环境基于Keil5嵌入式开发工具。
The ROV motion control system development environment is based on the Keil5 embedded development tools.  

## 分电板 Eletric transfer plate
分电板可以为水下无人机各个子系统进行电力分配
## 地面站主板 Ground station board
地面站主板主要负责运行地面站程序
## 控制器主板 Controller main board
控制器主板提供传感器接口，并运行水下无人机姿态控制程序


