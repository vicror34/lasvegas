cmake_minimum_required(VERSION 3.5)
project(Framework_EGC_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(libs)
include_directories(libs/Engine)
include_directories(Source)

add_executable(Framework_EGC_master
        libs/assimp/Compiler/poppack1.h
        libs/assimp/Compiler/pstdint.h
        libs/assimp/Compiler/pushpack1.h
        libs/assimp/ai_assert.h
        libs/assimp/anim.h
        libs/assimp/camera.h
        libs/assimp/cexport.h
        libs/assimp/cfileio.h
        libs/assimp/cimport.h
        libs/assimp/color4.h
        libs/assimp/color4.inl
        libs/assimp/config.h
        libs/assimp/DefaultLogger.hpp
        libs/assimp/defs.h
        libs/assimp/Exporter.hpp
        libs/assimp/Importer.hpp
        libs/assimp/importerdesc.h
        libs/assimp/IOStream.hpp
        libs/assimp/IOSystem.hpp
        libs/assimp/light.h
        libs/assimp/Logger.hpp
        libs/assimp/LogStream.hpp
        libs/assimp/material.h
        libs/assimp/material.inl
        libs/assimp/matrix3x3.h
        libs/assimp/matrix3x3.inl
        libs/assimp/matrix4x4.h
        libs/assimp/matrix4x4.inl
        libs/assimp/mesh.h
        libs/assimp/metadata.h
        libs/assimp/NullLogger.hpp
        libs/assimp/postprocess.h
        libs/assimp/ProgressHandler.hpp
        libs/assimp/quaternion.h
        libs/assimp/quaternion.inl
        libs/assimp/scene.h
        libs/assimp/texture.h
        libs/assimp/types.h
        libs/assimp/vector2.h
        libs/assimp/vector2.inl
        libs/assimp/vector3.h
        libs/assimp/vector3.inl
        libs/assimp/version.h
        libs/Engine/Component/Camera/Camera.h
        libs/Engine/Component/Transform/Transform.h
        libs/Engine/DLL/dll_export.h
        libs/GL/eglew.h
        libs/GL/glew.h
        libs/GL/glxew.h
        libs/GL/wglew.h
        libs/GLFW/glfw3.h
        libs/GLFW/glfw3native.h
        libs/glm/detail/_features.hpp
        libs/glm/detail/_fixes.hpp
        libs/glm/detail/_noise.hpp
        libs/glm/detail/_swizzle.hpp
        libs/glm/detail/_swizzle_func.hpp
        libs/glm/detail/_vectorize.hpp
        libs/glm/detail/dummy.cpp
        libs/glm/detail/func_common.hpp
        libs/glm/detail/func_common.inl
        libs/glm/detail/func_common_simd.inl
        libs/glm/detail/func_exponential.hpp
        libs/glm/detail/func_exponential.inl
        libs/glm/detail/func_exponential_simd.inl
        libs/glm/detail/func_geometric.hpp
        libs/glm/detail/func_geometric.inl
        libs/glm/detail/func_geometric_simd.inl
        libs/glm/detail/func_integer.hpp
        libs/glm/detail/func_integer.inl
        libs/glm/detail/func_integer_simd.inl
        libs/glm/detail/func_matrix.hpp
        libs/glm/detail/func_matrix.inl
        libs/glm/detail/func_matrix_simd.inl
        libs/glm/detail/func_packing.hpp
        libs/glm/detail/func_packing.inl
        libs/glm/detail/func_packing_simd.inl
        libs/glm/detail/func_trigonometric.hpp
        libs/glm/detail/func_trigonometric.inl
        libs/glm/detail/func_trigonometric_simd.inl
        libs/glm/detail/func_vector_relational.hpp
        libs/glm/detail/func_vector_relational.inl
        libs/glm/detail/func_vector_relational_simd.inl
        libs/glm/detail/glm.cpp
        libs/glm/detail/precision.hpp
        libs/glm/detail/setup.hpp
        libs/glm/detail/type_float.hpp
        libs/glm/detail/type_gentype.hpp
        libs/glm/detail/type_gentype.inl
        libs/glm/detail/type_half.hpp
        libs/glm/detail/type_half.inl
        libs/glm/detail/type_int.hpp
        libs/glm/detail/type_mat.hpp
        libs/glm/detail/type_mat.inl
        libs/glm/detail/type_mat2x2.hpp
        libs/glm/detail/type_mat2x2.inl
        libs/glm/detail/type_mat2x3.hpp
        libs/glm/detail/type_mat2x3.inl
        libs/glm/detail/type_mat2x4.hpp
        libs/glm/detail/type_mat2x4.inl
        libs/glm/detail/type_mat3x2.hpp
        libs/glm/detail/type_mat3x2.inl
        libs/glm/detail/type_mat3x3.hpp
        libs/glm/detail/type_mat3x3.inl
        libs/glm/detail/type_mat3x4.hpp
        libs/glm/detail/type_mat3x4.inl
        libs/glm/detail/type_mat4x2.hpp
        libs/glm/detail/type_mat4x2.inl
        libs/glm/detail/type_mat4x3.hpp
        libs/glm/detail/type_mat4x3.inl
        libs/glm/detail/type_mat4x4.hpp
        libs/glm/detail/type_mat4x4.inl
        libs/glm/detail/type_mat4x4_simd.inl
        libs/glm/detail/type_vec.hpp
        libs/glm/detail/type_vec.inl
        libs/glm/detail/type_vec1.hpp
        libs/glm/detail/type_vec1.inl
        libs/glm/detail/type_vec2.hpp
        libs/glm/detail/type_vec2.inl
        libs/glm/detail/type_vec3.hpp
        libs/glm/detail/type_vec3.inl
        libs/glm/detail/type_vec4.hpp
        libs/glm/detail/type_vec4.inl
        libs/glm/detail/type_vec4_simd.inl
        libs/glm/gtc/bitfield.hpp
        libs/glm/gtc/bitfield.inl
        libs/glm/gtc/color_encoding.inl
        libs/glm/gtc/color_space.hpp
        libs/glm/gtc/color_space.inl
        libs/glm/gtc/constants.hpp
        libs/glm/gtc/constants.inl
        libs/glm/gtc/epsilon.hpp
        libs/glm/gtc/epsilon.inl
        libs/glm/gtc/functions.hpp
        libs/glm/gtc/functions.inl
        libs/glm/gtc/integer.hpp
        libs/glm/gtc/integer.inl
        libs/glm/gtc/matrix_access.hpp
        libs/glm/gtc/matrix_access.inl
        libs/glm/gtc/matrix_integer.hpp
        libs/glm/gtc/matrix_inverse.hpp
        libs/glm/gtc/matrix_inverse.inl
        libs/glm/gtc/matrix_transform.hpp
        libs/glm/gtc/matrix_transform.inl
        libs/glm/gtc/noise.hpp
        libs/glm/gtc/noise.inl
        libs/glm/gtc/packing.hpp
        libs/glm/gtc/packing.inl
        libs/glm/gtc/quaternion.hpp
        libs/glm/gtc/quaternion.inl
        libs/glm/gtc/quaternion_simd.inl
        libs/glm/gtc/random.hpp
        libs/glm/gtc/random.inl
        libs/glm/gtc/reciprocal.hpp
        libs/glm/gtc/reciprocal.inl
        libs/glm/gtc/round.hpp
        libs/glm/gtc/round.inl
        libs/glm/gtc/type_aligned.hpp
        libs/glm/gtc/type_precision.hpp
        libs/glm/gtc/type_precision.inl
        libs/glm/gtc/type_ptr.hpp
        libs/glm/gtc/type_ptr.inl
        libs/glm/gtc/ulp.hpp
        libs/glm/gtc/ulp.inl
        libs/glm/gtc/vec1.hpp
        libs/glm/gtc/vec1.inl
        libs/glm/gtx/associated_min_max.hpp
        libs/glm/gtx/associated_min_max.inl
        libs/glm/gtx/bit.hpp
        libs/glm/gtx/bit.inl
        libs/glm/gtx/closest_point.hpp
        libs/glm/gtx/closest_point.inl
        libs/glm/gtx/color_space.hpp
        libs/glm/gtx/color_space.inl
        libs/glm/gtx/color_space_YCoCg.hpp
        libs/glm/gtx/color_space_YCoCg.inl
        libs/glm/gtx/common.hpp
        libs/glm/gtx/common.inl
        libs/glm/gtx/compatibility.hpp
        libs/glm/gtx/compatibility.inl
        libs/glm/gtx/component_wise.hpp
        libs/glm/gtx/component_wise.inl
        libs/glm/gtx/dual_quaternion.hpp
        libs/glm/gtx/dual_quaternion.inl
        libs/glm/gtx/euler_angles.hpp
        libs/glm/gtx/euler_angles.inl
        libs/glm/gtx/extend.hpp
        libs/glm/gtx/extend.inl
        libs/glm/gtx/extended_min_max.hpp
        libs/glm/gtx/extended_min_max.inl
        libs/glm/gtx/fast_exponential.hpp
        libs/glm/gtx/fast_exponential.inl
        libs/glm/gtx/fast_square_root.hpp
        libs/glm/gtx/fast_square_root.inl
        libs/glm/gtx/fast_trigonometry.hpp
        libs/glm/gtx/fast_trigonometry.inl
        libs/glm/gtx/float_notmalize.inl
        libs/glm/gtx/gradient_paint.hpp
        libs/glm/gtx/gradient_paint.inl
        libs/glm/gtx/handed_coordinate_space.hpp
        libs/glm/gtx/handed_coordinate_space.inl
        libs/glm/gtx/hash.hpp
        libs/glm/gtx/hash.inl
        libs/glm/gtx/integer.hpp
        libs/glm/gtx/integer.inl
        libs/glm/gtx/intersect.hpp
        libs/glm/gtx/intersect.inl
        libs/glm/gtx/io.hpp
        libs/glm/gtx/io.inl
        libs/glm/gtx/log_base.hpp
        libs/glm/gtx/log_base.inl
        libs/glm/gtx/matrix_cross_product.hpp
        libs/glm/gtx/matrix_cross_product.inl
        libs/glm/gtx/matrix_decompose.hpp
        libs/glm/gtx/matrix_decompose.inl
        libs/glm/gtx/matrix_interpolation.hpp
        libs/glm/gtx/matrix_interpolation.inl
        libs/glm/gtx/matrix_major_storage.hpp
        libs/glm/gtx/matrix_major_storage.inl
        libs/glm/gtx/matrix_operation.hpp
        libs/glm/gtx/matrix_operation.inl
        libs/glm/gtx/matrix_query.hpp
        libs/glm/gtx/matrix_query.inl
        libs/glm/gtx/matrix_transform_2d.hpp
        libs/glm/gtx/matrix_transform_2d.inl
        libs/glm/gtx/mixed_product.hpp
        libs/glm/gtx/mixed_product.inl
        libs/glm/gtx/norm.hpp
        libs/glm/gtx/norm.inl
        libs/glm/gtx/normal.hpp
        libs/glm/gtx/normal.inl
        libs/glm/gtx/normalize_dot.hpp
        libs/glm/gtx/normalize_dot.inl
        libs/glm/gtx/number_precision.hpp
        libs/glm/gtx/number_precision.inl
        libs/glm/gtx/optimum_pow.hpp
        libs/glm/gtx/optimum_pow.inl
        libs/glm/gtx/orthonormalize.hpp
        libs/glm/gtx/orthonormalize.inl
        libs/glm/gtx/perpendicular.hpp
        libs/glm/gtx/perpendicular.inl
        libs/glm/gtx/polar_coordinates.hpp
        libs/glm/gtx/polar_coordinates.inl
        libs/glm/gtx/projection.hpp
        libs/glm/gtx/projection.inl
        libs/glm/gtx/quaternion.hpp
        libs/glm/gtx/quaternion.inl
        libs/glm/gtx/range.hpp
        libs/glm/gtx/raw_data.hpp
        libs/glm/gtx/raw_data.inl
        libs/glm/gtx/rotate_normalized_axis.hpp
        libs/glm/gtx/rotate_normalized_axis.inl
        libs/glm/gtx/rotate_vector.hpp
        libs/glm/gtx/rotate_vector.inl
        libs/glm/gtx/scalar_multiplication.hpp
        libs/glm/gtx/scalar_relational.hpp
        libs/glm/gtx/scalar_relational.inl
        libs/glm/gtx/simd_mat4.hpp
        libs/glm/gtx/simd_mat4.inl
        libs/glm/gtx/simd_quat.hpp
        libs/glm/gtx/simd_quat.inl
        libs/glm/gtx/simd_vec4.hpp
        libs/glm/gtx/simd_vec4.inl
        libs/glm/gtx/spline.hpp
        libs/glm/gtx/spline.inl
        libs/glm/gtx/std_based_type.hpp
        libs/glm/gtx/std_based_type.inl
        libs/glm/gtx/string_cast.hpp
        libs/glm/gtx/string_cast.inl
        libs/glm/gtx/transform.hpp
        libs/glm/gtx/transform.inl
        libs/glm/gtx/transform2.hpp
        libs/glm/gtx/transform2.inl
        libs/glm/gtx/type_aligned.hpp
        libs/glm/gtx/type_aligned.inl
        libs/glm/gtx/type_trait.hpp
        libs/glm/gtx/type_trait.inl
        libs/glm/gtx/vector_angle.hpp
        libs/glm/gtx/vector_angle.inl
        libs/glm/gtx/vector_query.hpp
        libs/glm/gtx/vector_query.inl
        libs/glm/gtx/wrap.hpp
        libs/glm/gtx/wrap.inl
        libs/glm/simd/common.h
        libs/glm/simd/exponential.h
        libs/glm/simd/geometric.h
        libs/glm/simd/integer.h
        libs/glm/simd/matrix.h
        libs/glm/simd/packing.h
        libs/glm/simd/platform.h
        libs/glm/simd/trigonometric.h
        libs/glm/simd/vector_relational.h
        libs/glm/common.hpp
        libs/glm/exponential.hpp
        libs/glm/ext.hpp
        libs/glm/fwd.hpp
        libs/glm/geometric.hpp
        libs/glm/glm.hpp
        libs/glm/integer.hpp
        libs/glm/mat2x2.hpp
        libs/glm/mat2x3.hpp
        libs/glm/mat2x4.hpp
        libs/glm/mat3x2.hpp
        libs/glm/mat3x3.hpp
        libs/glm/mat3x4.hpp
        libs/glm/mat4x2.hpp
        libs/glm/mat4x3.hpp
        libs/glm/mat4x4.hpp
        libs/glm/matrix.hpp
        libs/glm/packing.hpp
        libs/glm/trigonometric.hpp
        libs/glm/vec2.hpp
        libs/glm/vec3.hpp
        libs/glm/vec4.hpp
        libs/glm/vector_relational.hpp
        libs/stb/stb_image.h
        libs/stb/stb_image_write.h
        Source/Component/CameraInput.cpp
        Source/Component/CameraInput.h
        Source/Component/SceneInput.cpp
        Source/Component/SceneInput.h
        Source/Component/SimpleScene.cpp
        Source/Component/SimpleScene.h
        Source/Core/GPU/GPUBuffers.cpp
        Source/Core/GPU/GPUBuffers.h
        Source/Core/GPU/Mesh.cpp
        Source/Core/GPU/Mesh.h
        Source/Core/GPU/Shader.cpp
        Source/Core/GPU/Shader.h
        Source/Core/GPU/Texture2D.cpp
        Source/Core/GPU/Texture2D.h
        Source/Core/Managers/ResourcePath.h
        Source/Core/Managers/TextureManager.cpp
        Source/Core/Managers/TextureManager.h
        Source/Core/Window/InputController.cpp
        Source/Core/Window/InputController.h
        Source/Core/Window/WindowCallbacks.cpp
        Source/Core/Window/WindowCallbacks.h
        #    Source/Core/Window/WindowObject.cpp
        #    Source/Core/Window/WindowObject.h
        Source/Core/Engine.cpp
        Source/Core/Engine.h
        Source/Core/World.cpp
        Source/Core/World.h
        Source/include/gl.cpp
        Source/include/gl.h
        Source/include/glm.h
        Source/include/math.h
        Source/include/utils.h
        Source/Laboratoare/Laborator1/Laborator1.cpp
        Source/Laboratoare/Laborator1/Laborator1.h
        Source/Laboratoare/Laborator2/Laborator2.cpp
        Source/Laboratoare/Laborator2/Laborator2.h
        Source/Laboratoare/Laborator3/Laborator3.cpp
        Source/Laboratoare/Laborator3/Laborator3.h
        Source/Laboratoare/Laborator3/Laborator3_Vis2D.cpp
        Source/Laboratoare/Laborator3/Laborator3_Vis2D.h
        Source/Laboratoare/Laborator3/Object2D.cpp
        Source/Laboratoare/Laborator3/Object2D.h
        Source/Laboratoare/Laborator3/Transform2D.h
        Source/Laboratoare/Laborator4/Laborator4.cpp
        Source/Laboratoare/Laborator4/Laborator4.h
        Source/Laboratoare/Laborator4/Transform3D.h
        Source/Laboratoare/Laborator5/LabCamera.h
        Source/Laboratoare/Laborator5/Laborator5.cpp
        Source/Laboratoare/Laborator5/Laborator5.h
        Source/Laboratoare/Laborator6/Laborator6.cpp
        Source/Laboratoare/Laborator6/Laborator6.h
        Source/Laboratoare/Laborator7/Laborator7.cpp
        Source/Laboratoare/Laborator7/Laborator7.h
        Source/Laboratoare/Laborator8/Laborator8.cpp
        Source/Laboratoare/Laborator8/Laborator8.h
        Source/Laboratoare/Laborator9/Laborator9.cpp
        Source/Laboratoare/Laborator9/Laborator9.h
        Source/Laboratoare/LabList.h
        Source/Main.cpp
        Source/Laboratoare/Tema3/tema3.cpp
        Source/Laboratoare/Tema3/tema3.h)