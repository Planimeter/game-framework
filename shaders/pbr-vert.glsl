#version 330
in vec4 position;
#define HAS_NORMALS
#ifdef HAS_NORMALS
in vec4 normal;
#endif
#ifdef HAS_TANGENTS
in vec4 a_Tangent;
#endif
#define HAS_UV
#ifdef HAS_UV
in vec2 texcoord;
#endif

// uniform mat4 u_MVPMatrix;
// uniform mat4 u_ModelMatrix;
uniform mat4 u_NormalMatrix;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 v_Position;
out vec2 v_UV;

#ifdef HAS_NORMALS
#ifdef HAS_TANGENTS
out mat3 v_TBN;
#else
out vec3 v_Normal;
#endif
#endif


void main()
{
  vec4 pos = model * position;
  v_Position = vec3(pos.xyz) / pos.w;

  #ifdef HAS_NORMALS
  #ifdef HAS_TANGENTS
  vec3 normalW = normalize(vec3(u_NormalMatrix * vec4(normal.xyz, 0.0)));
  vec3 tangentW = normalize(vec3(model * vec4(a_Tangent.xyz, 0.0)));
  vec3 bitangentW = cross(normalW, tangentW) * a_Tangent.w;
  v_TBN = mat3(tangentW, bitangentW, normalW);
  #else // HAS_TANGENTS != 1
  v_Normal = normalize(vec3(model * vec4(normal.xyz, 0.0)));
  #endif
  #endif

  #ifdef HAS_UV
  v_UV = texcoord;
  #else
  v_UV = vec2(0.,0.);
  #endif

  // gl_Position = u_MVPMatrix * position; // needs w for proper perspective correction
  gl_Position = projection * view * model * position; // needs w for proper perspective correction
}
