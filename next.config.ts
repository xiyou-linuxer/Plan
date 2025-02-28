import nextra from "nextra";

const withNextra = nextra({});

export default withNextra({
  cleanDistDir: true,
  eslint: {
    ignoreDuringBuilds: true,
  },
  images: {
    unoptimized: true,
  },
  output: "export",
  reactStrictMode: true,
});
