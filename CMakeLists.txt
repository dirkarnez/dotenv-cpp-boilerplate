cmake_minimum_required(VERSION 3.19)

project(dotenv-cpp-boilerplate)

# version is only declared in header file, no cmake declaration is made
find_package(laserpants_dotenv REQUIRED PATHS ${DOTENV_CPP_ROOT})

if (laserpants_dotenv_FOUND)
    message("laserpants_dotenv found")

    # Does not work
    # target_sources(laserpants::dotenv INTERFACE "src/setenv.hpp")

else (laserpants_dotenv_FOUND)
    message("laserpants_dotenv not found")
endif()


add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} laserpants::dotenv)