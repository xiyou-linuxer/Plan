import antfu from '@antfu/eslint-config'

export default antfu({
  rules: {
    'style/jsx-one-expression-per-line': 'off',
  },
}, {
  files: ['**/*.json'],
  ignores: ['content/**'],
  rules: {
    'style/eol-last': ['warn', 'never'],
  },
})
