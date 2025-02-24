import nextra from 'nextra'

const withNextra = nextra({

})

export default withNextra({
  output: 'export',
  images: {
    unoptimized: true,
  },
  eslint: {
    ignoreDuringBuilds: true,
  },
  reactStrictMode: true,
  cleanDistDir: true,
})
