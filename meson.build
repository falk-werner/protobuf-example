project('protobuf-example', 'cpp', default_options: ['cpp_std=c++14'])

protoc = find_program('protoc')
protobuf_dep = dependency('protobuf')

gen_src = custom_target('gen',
    input: ['greeter.proto'],
    output: ['greeter.pb.cc', 'greeter.pb.h'],
    command: [protoc, '-I@CURRENT_SOURCE_DIR@', '--cpp_out=.', '@INPUT@'])

executable('protobuf-example', [
        'src/main.cpp',
        gen_src
    ],
    dependencies: [protobuf_dep])

