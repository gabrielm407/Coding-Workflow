# My C++ Project

This project is a C++ application that demonstrates the use of utility functions and includes a simple structure for building and testing.

## Project Structure

```
Coding workflow
├── src
│   ├── main.cpp         # Entry point of the application
│   ├── utils.cpp        # Implementation of utility functions
│   └── utils.hpp        # Header file for utility functions
├── tests
│   └── sample_input.txt # Sample input data for testing
├── .github
│   └── workflows
│       ├── ci-on-pr.yml # CI workflow for pull requests
│       └── ci-on-merge.yml # CI workflow for merged pull requests
├── CMakeLists.txt       # CMake configuration file
├── Makefile             # Makefile for building the project
├── .gitignore           # Files and directories to ignore by Git
└── README.md            # Project documentation
```

## Building the Project

To build the project, you can use either CMake or Make. 

### Using CMake

1. Navigate to the project directory:
   ```
   cd my-cpp-project
   ```
2. Create a build directory:
   ```
   mkdir build && cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   make
   ```

### Using Make

Simply run:
```
make
```

## Running the Application

After building the project, you can run the application using:
```
./your_executable_name
```

## Testing

The project includes a sample input file located in the `tests` directory. You can use this file to test the application.

## CI/CD

This project is set up with GitHub Actions to automatically run the C++ code when a pull request is made and when it is merged. The workflows are defined in the `.github/workflows` directory.

## Contributing

Feel free to fork the repository and submit pull requests for any improvements or bug fixes.