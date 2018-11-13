#    Roboworkers
----
### C++  single producer and multiple consumers multithreading demonstration
##### Based on requirements of a coding challenge.
![roboworkers](https://raw.githubusercontent.com/kabasakalis/roboworkers/master/roboworkers.jpg)
![roboworkers](https://raw.githubusercontent.com/kabasakalis/roboworkers/master/console_showcase.png)

## Challenge requirements
The goal of this challenge is to simulate a factory with inbound and outbound requests for storing or delivering
furniture products. A single packager packages the products. A team of workers concurrently processes the requests from a queue to which the backoffice adds entries in batches. The whole workflow is outlined with logs.
## Build Debug Instructions
- To configure the CMake project, run at the root directory:
```cmake -DCMAKE_BUILD_TYPE=Debug  ./cmake-build-debug```
- To build the project, run at the root of the directory:
 ```cmake --build ./cmake-build-debug --target roboworkers -- -j 2```
- To run the executable, run at the root of the directory:
```./cmake-build-debug/roboworkers```

