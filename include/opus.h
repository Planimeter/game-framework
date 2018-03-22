

   typedef int16_t opus_int16;
   typedef uint16_t opus_uint16;
   typedef int32_t opus_int32;
   typedef uint32_t opus_uint32;
            const char *opus_strerror(int error);
            const char *opus_get_version_string(void);
typedef struct OpusEncoder OpusEncoder;






            __attribute__ ((__warn_unused_result__)) int opus_encoder_get_size(int channels);
            __attribute__ ((__warn_unused_result__)) OpusEncoder *opus_encoder_create(
    opus_int32 Fs,
    int channels,
    int application,
    int *error
);
            int opus_encoder_init(
    OpusEncoder *st,
    opus_int32 Fs,
    int channels,
    int application
) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_encode(
    OpusEncoder *st,
    const opus_int16 *pcm,
    int frame_size,
    unsigned char *data,
    opus_int32 max_data_bytes
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2))) __attribute__ ((__nonnull__(4)));
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_encode_float(
    OpusEncoder *st,
    const float *pcm,
    int frame_size,
    unsigned char *data,
    opus_int32 max_data_bytes
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2))) __attribute__ ((__nonnull__(4)));




            void opus_encoder_destroy(OpusEncoder *st);
            int opus_encoder_ctl(OpusEncoder *st, int request, ...) __attribute__ ((__nonnull__(1)));
typedef struct OpusDecoder OpusDecoder;






            __attribute__ ((__warn_unused_result__)) int opus_decoder_get_size(int channels);
            __attribute__ ((__warn_unused_result__)) OpusDecoder *opus_decoder_create(
    opus_int32 Fs,
    int channels,
    int *error
);
            int opus_decoder_init(
    OpusDecoder *st,
    opus_int32 Fs,
    int channels
) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) int opus_decode(
    OpusDecoder *st,
    const unsigned char *data,
    opus_int32 len,
    opus_int16 *pcm,
    int frame_size,
    int decode_fec
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
            __attribute__ ((__warn_unused_result__)) int opus_decode_float(
    OpusDecoder *st,
    const unsigned char *data,
    opus_int32 len,
    float *pcm,
    int frame_size,
    int decode_fec
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
            int opus_decoder_ctl(OpusDecoder *st, int request, ...) __attribute__ ((__nonnull__(1)));




            void opus_decoder_destroy(OpusDecoder *st);
            int opus_packet_parse(
   const unsigned char *data,
   opus_int32 len,
   unsigned char *out_toc,
   const unsigned char *frames[48],
   opus_int16 size[48],
   int *payload_offset
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
            __attribute__ ((__warn_unused_result__)) int opus_packet_get_bandwidth(const unsigned char *data) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) int opus_packet_get_samples_per_frame(const unsigned char *data, opus_int32 Fs) __attribute__ ((__nonnull__(1)));






            __attribute__ ((__warn_unused_result__)) int opus_packet_get_nb_channels(const unsigned char *data) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) int opus_packet_get_nb_frames(const unsigned char packet[], opus_int32 len) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) int opus_packet_get_nb_samples(const unsigned char packet[], opus_int32 len, opus_int32 Fs) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) int opus_decoder_get_nb_samples(const OpusDecoder *dec, const unsigned char packet[], opus_int32 len) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2)));
            void opus_pcm_soft_clip(float *pcm, int frame_size, int channels, float *softclip_mem);
typedef struct OpusRepacketizer OpusRepacketizer;




            __attribute__ ((__warn_unused_result__)) int opus_repacketizer_get_size(void);
            OpusRepacketizer *opus_repacketizer_init(OpusRepacketizer *rp) __attribute__ ((__nonnull__(1)));




            __attribute__ ((__warn_unused_result__)) OpusRepacketizer *opus_repacketizer_create(void);





            void opus_repacketizer_destroy(OpusRepacketizer *rp);
            int opus_repacketizer_cat(OpusRepacketizer *rp, const unsigned char *data, opus_int32 len) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2)));
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_repacketizer_out_range(OpusRepacketizer *rp, int begin, int end, unsigned char *data, opus_int32 maxlen) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
            __attribute__ ((__warn_unused_result__)) int opus_repacketizer_get_nb_frames(OpusRepacketizer *rp) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_repacketizer_out(OpusRepacketizer *rp, unsigned char *data, opus_int32 maxlen) __attribute__ ((__nonnull__(1)));
            int opus_packet_pad(unsigned char *data, opus_int32 len, opus_int32 new_len);
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_packet_unpad(unsigned char *data, opus_int32 len);
            int opus_multistream_packet_pad(unsigned char *data, opus_int32 len, opus_int32 new_len, int nb_streams);
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_multistream_packet_unpad(unsigned char *data, opus_int32 len, int nb_streams);
typedef struct OpusCustomEncoder OpusCustomEncoder;






typedef struct OpusCustomDecoder OpusCustomDecoder;







typedef struct OpusCustomMode OpusCustomMode;
                   __attribute__ ((__warn_unused_result__)) OpusCustomMode *opus_custom_mode_create(opus_int32 Fs, int frame_size, int *error);





                   void opus_custom_mode_destroy(OpusCustomMode *mode);
                          __attribute__ ((__warn_unused_result__)) int opus_custom_encoder_get_size(
    const OpusCustomMode *mode,
    int channels
) __attribute__ ((__nonnull__(1)));
                   __attribute__ ((__warn_unused_result__)) OpusCustomEncoder *opus_custom_encoder_create(
    const OpusCustomMode *mode,
    int channels,
    int *error
) __attribute__ ((__nonnull__(1)));





                   void opus_custom_encoder_destroy(OpusCustomEncoder *st);
                   __attribute__ ((__warn_unused_result__)) int opus_custom_encode_float(
    OpusCustomEncoder *st,
    const float *pcm,
    int frame_size,
    unsigned char *compressed,
    int maxCompressedBytes
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2))) __attribute__ ((__nonnull__(4)));
                   __attribute__ ((__warn_unused_result__)) int opus_custom_encode(
    OpusCustomEncoder *st,
    const opus_int16 *pcm,
    int frame_size,
    unsigned char *compressed,
    int maxCompressedBytes
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2))) __attribute__ ((__nonnull__(4)));







                   int opus_custom_encoder_ctl(OpusCustomEncoder * restrict st, int request, ...) __attribute__ ((__nonnull__(1)));
                          __attribute__ ((__warn_unused_result__)) int opus_custom_decoder_get_size(
    const OpusCustomMode *mode,
    int channels
) __attribute__ ((__nonnull__(1)));
                          int opus_custom_decoder_init(
    OpusCustomDecoder *st,
    const OpusCustomMode *mode,
    int channels
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2)));
                   __attribute__ ((__warn_unused_result__)) OpusCustomDecoder *opus_custom_decoder_create(
    const OpusCustomMode *mode,
    int channels,
    int *error
) __attribute__ ((__nonnull__(1)));




                   void opus_custom_decoder_destroy(OpusCustomDecoder *st);
                   __attribute__ ((__warn_unused_result__)) int opus_custom_decode_float(
    OpusCustomDecoder *st,
    const unsigned char *data,
    int len,
    float *pcm,
    int frame_size
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
                   __attribute__ ((__warn_unused_result__)) int opus_custom_decode(
    OpusCustomDecoder *st,
    const unsigned char *data,
    int len,
    opus_int16 *pcm,
    int frame_size
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));







                   int opus_custom_decoder_ctl(OpusCustomDecoder * restrict st, int request, ...) __attribute__ ((__nonnull__(1)));
typedef struct OpusMSEncoder OpusMSEncoder;







typedef struct OpusMSDecoder OpusMSDecoder;
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_multistream_encoder_get_size(
      int streams,
      int coupled_streams
);

            __attribute__ ((__warn_unused_result__)) opus_int32 opus_multistream_surround_encoder_get_size(
      int channels,
      int mapping_family
);
            __attribute__ ((__warn_unused_result__)) OpusMSEncoder *opus_multistream_encoder_create(
      opus_int32 Fs,
      int channels,
      int streams,
      int coupled_streams,
      const unsigned char *mapping,
      int application,
      int *error
) __attribute__ ((__nonnull__(5)));

            __attribute__ ((__warn_unused_result__)) OpusMSEncoder *opus_multistream_surround_encoder_create(
      opus_int32 Fs,
      int channels,
      int mapping_family,
      int *streams,
      int *coupled_streams,
      unsigned char *mapping,
      int application,
      int *error
) __attribute__ ((__nonnull__(4))) __attribute__ ((__nonnull__(5))) __attribute__ ((__nonnull__(6)));
            int opus_multistream_encoder_init(
      OpusMSEncoder *st,
      opus_int32 Fs,
      int channels,
      int streams,
      int coupled_streams,
      const unsigned char *mapping,
      int application
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(6)));

            int opus_multistream_surround_encoder_init(
      OpusMSEncoder *st,
      opus_int32 Fs,
      int channels,
      int mapping_family,
      int *streams,
      int *coupled_streams,
      unsigned char *mapping,
      int application
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(5))) __attribute__ ((__nonnull__(6))) __attribute__ ((__nonnull__(7)));
            __attribute__ ((__warn_unused_result__)) int opus_multistream_encode(
    OpusMSEncoder *st,
    const opus_int16 *pcm,
    int frame_size,
    unsigned char *data,
    opus_int32 max_data_bytes
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2))) __attribute__ ((__nonnull__(4)));
            __attribute__ ((__warn_unused_result__)) int opus_multistream_encode_float(
      OpusMSEncoder *st,
      const float *pcm,
      int frame_size,
      unsigned char *data,
      opus_int32 max_data_bytes
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(2))) __attribute__ ((__nonnull__(4)));





            void opus_multistream_encoder_destroy(OpusMSEncoder *st);
            int opus_multistream_encoder_ctl(OpusMSEncoder *st, int request, ...) __attribute__ ((__nonnull__(1)));
            __attribute__ ((__warn_unused_result__)) opus_int32 opus_multistream_decoder_get_size(
      int streams,
      int coupled_streams
);
            __attribute__ ((__warn_unused_result__)) OpusMSDecoder *opus_multistream_decoder_create(
      opus_int32 Fs,
      int channels,
      int streams,
      int coupled_streams,
      const unsigned char *mapping,
      int *error
) __attribute__ ((__nonnull__(5)));
            int opus_multistream_decoder_init(
      OpusMSDecoder *st,
      opus_int32 Fs,
      int channels,
      int streams,
      int coupled_streams,
      const unsigned char *mapping
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(6)));
            __attribute__ ((__warn_unused_result__)) int opus_multistream_decode(
    OpusMSDecoder *st,
    const unsigned char *data,
    opus_int32 len,
    opus_int16 *pcm,
    int frame_size,
    int decode_fec
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
            __attribute__ ((__warn_unused_result__)) int opus_multistream_decode_float(
    OpusMSDecoder *st,
    const unsigned char *data,
    opus_int32 len,
    float *pcm,
    int frame_size,
    int decode_fec
) __attribute__ ((__nonnull__(1))) __attribute__ ((__nonnull__(4)));
            int opus_multistream_decoder_ctl(OpusMSDecoder *st, int request, ...) __attribute__ ((__nonnull__(1)));





            void opus_multistream_decoder_destroy(OpusMSDecoder *st);
